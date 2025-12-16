#include "main.h"
#include "drive.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/motors.h"


const float RAYCAST_RESET_ANGLE_RANGE = 20.0; // ± degrees from 0°/360° or 90°/270° 
const float RAYCAST_RESET_MIN_ERROR = 0.0; // minimum error required before applying correction
const float RAYCAST_RESET_MAX_ERROR = 3.0; // maximum error to restrict correction (e.g. matchloader depth)

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);

	chassis.calibrate();

	chassis.setPose(0,0,90);

	pros::Task distance_resets([&] {

		while(false) {

			float frontReading = front_dist.get() * MM_TO_IN;
			float leftReading = left_dist.get() * MM_TO_IN;
			float rightReading = right_dist.get() * MM_TO_IN;
			float backReading = back_dist.get() * MM_TO_IN;
			float frontLeftReading = 0;
			float frontRightReading = 0;
			float backLeftReading = 0;
			float backRightReading = 0;

			float frontConfidence = front_dist.get_confidence();
			float leftConfidence = left_dist.get_confidence();
			float rightConfidence = right_dist.get_confidence();
			float backConfidence = back_dist.get_confidence();
			float frontLeftConfidence = 1.0;
			float frontRightConfidence = 1.0;
			float backLeftConfidence = 1.0;
			float backRightConfidence = 1.0;

			lemlib::Pose currentPose = chassis.getPose();
					
			float estimated_x = currentPose.x;
			float estimated_y = currentPose.y;

			float x_deviation = 144;
			float y_deviation = 144;

			float normalizedTheta = normalizeAngle(currentPose.theta);
			// std::printf("Normalized Theta: %.3f", normalizedTheta);

			float estimatedRightPos = 0;
			float estimatedFrontPos = 0;
			float estimatedLeftPos = 0;
			float estimatedBackPos = 0;

			WALL wallDirection = NORTH;
			bool parallel = false;

			float error_x = 144.0;
			float error_y = 144.0;

			if (fabs(normalizedTheta) < RAYCAST_RESET_ANGLE_RANGE/2.0) {
				parallel = true;
				wallDirection = NORTH;
			}
			else if (fabs(normalizedTheta - 180) < RAYCAST_RESET_ANGLE_RANGE/2.0) {
				parallel = true;
				wallDirection = SOUTH;
			}
			else if (fabs(normalizedTheta - 90) < RAYCAST_RESET_ANGLE_RANGE/2.0) {
				parallel = true;
				wallDirection = EAST;
			}
			else if (fabs(normalizedTheta - 270) < RAYCAST_RESET_ANGLE_RANGE/2.0) {
				parallel = true;
				wallDirection = WEST;
			}
			else if (fabs(normalizedTheta - 45) < RAYCAST_RESET_ANGLE_RANGE/2.0) {
				parallel = true;
				wallDirection = NE;
			}
			else if (fabs(normalizedTheta - 135) < RAYCAST_RESET_ANGLE_RANGE/2.0) {
				parallel = true;
				wallDirection = SE;
			}
			else if (fabs(normalizedTheta - 315) < RAYCAST_RESET_ANGLE_RANGE/2.0) {
				parallel = true;
				wallDirection = NW;
			}
			else if (fabs(normalizedTheta - 225) < RAYCAST_RESET_ANGLE_RANGE/2.0) {
				parallel = true;
				wallDirection = SW;
			}
			else {
				parallel = false;
			}
			
			if (parallel) {
				switch (wallDirection) {
					case NORTH:
						estimatedRightPos = positionFromRaycast(rightReading, RIGHT_DIST_OFFSET, EAST);
						estimatedFrontPos = positionFromRaycast(frontReading, FRONT_DIST_OFFSET, NORTH);
						estimatedLeftPos = positionFromRaycast(leftReading, LEFT_DIST_OFFSET, WEST);
						estimatedBackPos = positionFromRaycast(backReading, BACK_DIST_OFFSET, SOUTH);
						x_deviation = fabs(estimatedLeftPos - estimatedRightPos);
						y_deviation = fabs(estimatedFrontPos - estimatedBackPos);
						estimated_x = (leftConfidence * estimatedLeftPos + rightConfidence * estimatedRightPos) / (leftConfidence + rightConfidence);
						estimated_y = (frontConfidence * estimatedFrontPos + backConfidence * estimatedBackPos) / (frontConfidence + backConfidence);
						break;
					case SOUTH:
						estimatedRightPos = positionFromRaycast(rightReading, RIGHT_DIST_OFFSET, WEST);
						estimatedFrontPos = positionFromRaycast(frontReading, FRONT_DIST_OFFSET, SOUTH);
						estimatedLeftPos = positionFromRaycast(leftReading, LEFT_DIST_OFFSET, EAST);
						estimatedBackPos = positionFromRaycast(backReading, BACK_DIST_OFFSET, NORTH);
						x_deviation = fabs(estimatedLeftPos - estimatedRightPos);
						y_deviation = fabs(estimatedFrontPos - estimatedBackPos);
						estimated_x = (leftConfidence * estimatedLeftPos + rightConfidence * estimatedRightPos) / (leftConfidence + rightConfidence);
						estimated_y = (frontConfidence * estimatedFrontPos + backConfidence * estimatedBackPos) / (frontConfidence + backConfidence);
						break;
					case EAST:
						estimatedRightPos = positionFromRaycast(rightReading, RIGHT_DIST_OFFSET, SOUTH);
						estimatedFrontPos = positionFromRaycast(frontReading, FRONT_DIST_OFFSET, EAST);
						estimatedLeftPos = positionFromRaycast(leftReading, LEFT_DIST_OFFSET, NORTH);
						estimatedBackPos = positionFromRaycast(backReading, BACK_DIST_OFFSET, WEST);
						x_deviation = fabs(estimatedFrontPos - estimatedBackPos);
						y_deviation = fabs(estimatedLeftPos - estimatedRightPos);
						estimated_y = (leftConfidence * estimatedLeftPos + rightConfidence * estimatedRightPos) / (leftConfidence + rightConfidence);
						estimated_x = (frontConfidence * estimatedFrontPos + backConfidence * estimatedBackPos) / (frontConfidence + backConfidence);
						break;
					case WEST:
						estimatedRightPos = positionFromRaycast(rightReading, RIGHT_DIST_OFFSET, NORTH);
						estimatedFrontPos = positionFromRaycast(frontReading, FRONT_DIST_OFFSET, WEST);
						estimatedLeftPos = positionFromRaycast(leftReading, LEFT_DIST_OFFSET, SOUTH);
						estimatedBackPos = positionFromRaycast(backReading, BACK_DIST_OFFSET, EAST);
						x_deviation = fabs(estimatedFrontPos - estimatedBackPos);
						y_deviation = fabs(estimatedLeftPos - estimatedRightPos);
						estimated_y = (leftConfidence * estimatedLeftPos + rightConfidence * estimatedRightPos) / (leftConfidence + rightConfidence);
						estimated_x = (frontConfidence * estimatedFrontPos + backConfidence * estimatedBackPos) / (frontConfidence + backConfidence);
						break;
					case NE:
						estimatedRightPos = positionFromRaycast(frontRightReading, FRONTRIGHT_DIST_OFFSET, EAST);
						estimatedFrontPos = positionFromRaycast(frontLeftReading, FRONTLEFT_DIST_OFFSET, NORTH);
						estimatedLeftPos = positionFromRaycast(backLeftReading, BACKLEFT_DIST_OFFSET, WEST);
						estimatedBackPos = positionFromRaycast(backRightReading, BACKRIGHT_DIST_OFFSET, SOUTH);
						y_deviation = fabs(estimatedFrontPos - estimatedBackPos);
						x_deviation = fabs(estimatedLeftPos - estimatedRightPos);
						estimated_y = (frontLeftConfidence * estimatedFrontPos + backRightConfidence * estimatedBackPos) / (frontLeftConfidence + backRightConfidence);
						estimated_x = (backLeftConfidence * estimatedLeftPos + frontRightConfidence * estimatedRightPos) / (backLeftConfidence + frontRightConfidence);
						break;
					case SE:
						estimatedRightPos = positionFromRaycast(frontRightReading, FRONTRIGHT_DIST_OFFSET, SOUTH);
						estimatedFrontPos = positionFromRaycast(frontLeftReading, FRONTLEFT_DIST_OFFSET, EAST);
						estimatedLeftPos = positionFromRaycast(backLeftReading, BACKLEFT_DIST_OFFSET, NORTH);
						estimatedBackPos = positionFromRaycast(backRightReading, BACKRIGHT_DIST_OFFSET, WEST);
						x_deviation = fabs(estimatedFrontPos - estimatedBackPos);
						y_deviation = fabs(estimatedLeftPos - estimatedRightPos);
						estimated_x = (frontLeftConfidence * estimatedFrontPos + backRightConfidence * estimatedBackPos) / (frontLeftConfidence + backRightConfidence);
						estimated_y = (backLeftConfidence * estimatedLeftPos + frontRightConfidence * estimatedRightPos) / (backLeftConfidence + frontRightConfidence);
						break;
					case NW:
						estimatedRightPos = positionFromRaycast(frontRightReading, FRONTRIGHT_DIST_OFFSET, NORTH);
						estimatedFrontPos = positionFromRaycast(frontLeftReading, FRONTLEFT_DIST_OFFSET, WEST);
						estimatedLeftPos = positionFromRaycast(backLeftReading, BACKLEFT_DIST_OFFSET, SOUTH);
						estimatedBackPos = positionFromRaycast(backRightReading, BACKRIGHT_DIST_OFFSET, EAST);
						x_deviation = fabs(estimatedFrontPos - estimatedBackPos);
						y_deviation = fabs(estimatedLeftPos - estimatedRightPos);
						estimated_x = (frontLeftConfidence * estimatedFrontPos + backRightConfidence * estimatedBackPos) / (frontLeftConfidence + backRightConfidence);
						estimated_y = (backLeftConfidence * estimatedLeftPos + frontRightConfidence * estimatedRightPos) / (backLeftConfidence + frontRightConfidence);
						break;
					case SW:
						estimatedRightPos = positionFromRaycast(frontRightReading, FRONTRIGHT_DIST_OFFSET, WEST);
						estimatedFrontPos = positionFromRaycast(frontLeftReading, FRONTLEFT_DIST_OFFSET, SOUTH);
						estimatedLeftPos = positionFromRaycast(backLeftReading, BACKLEFT_DIST_OFFSET, EAST);
						estimatedBackPos = positionFromRaycast(backRightReading, BACKRIGHT_DIST_OFFSET, NORTH);
						y_deviation = fabs(estimatedFrontPos - estimatedBackPos);
						x_deviation = fabs(estimatedLeftPos - estimatedRightPos);
						estimated_y = (frontLeftConfidence * estimatedFrontPos + backRightConfidence * estimatedBackPos) / (frontLeftConfidence + backRightConfidence);
						estimated_x = (backLeftConfidence * estimatedLeftPos + frontRightConfidence * estimatedRightPos) / (backLeftConfidence + frontRightConfidence);
						break;
					default:
						std::printf("Invalid wall direction");
						break;
				}

				error_x = fabs(estimated_x - currentPose.x);
				error_y = fabs(estimated_y - currentPose.y);
				// std::printf("X_deviation: %.3f\nY_deviation: %.3f\n", x_deviation, y_deviation);

				// std::printf("X Error: %.3f, Y Error: %.3f\n", error_x, error_y);

				if (x_deviation >= RAYCAST_RESET_MIN_ERROR && x_deviation <= RAYCAST_RESET_MAX_ERROR && error_x > 0.3){
					chassis.setPose(estimated_x, chassis.getPose().y, chassis.getPose().theta);
					std::printf("X pos reset! %.3f Deviation: %.3f\n",estimated_x, x_deviation);
				}

				if (y_deviation >= RAYCAST_RESET_MIN_ERROR && y_deviation <= RAYCAST_RESET_MAX_ERROR && error_y > 0.3){
					chassis.setPose(chassis.getPose().x, estimated_y, chassis.getPose().theta);
					std::printf("Y pos reset! %.3f Deviation: %.3f\n", estimated_y, y_deviation);
				}
			}

		pros::delay(50);
	}
	});

	pros::Task print_coordinates([=](){
		while (true) {
			// std::cout << "Estimated pose: x=" << chassis.getPose().x << ", y=" << chassis.getPose().y << ", theta=" << chassis.getPose().theta;
			if (true) {
				// std::cout << std::endl;
				// std::printf("Estimated pose: x=%.3f, y=%.3f, theta=%.3f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
				// pros::lcd::print(0, "X:%.2f, Y:%.2f, Theta:%.2f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
				controller.print(0, 0, "X:%.2fY:%.2fT:%.2f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
				// master.print(0,0,"Dist Theta: %.3f", calculateHeading(chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta, -5.289,5.503,-5.63,-2.028,front_dist.get() * MM_TO_IN,left_dist.get() * MM_TO_IN, NORTH, WEST));
				pros::delay(100);
			}
		}
	});
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
	skills();
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {

	bool levelPressed = false;
	bool levelState = false;
	bool prevLevelState = false;

	bool pto_state=false;
	pto.set_value(false);


	int intake_speed=127;

	chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
	intake.set_brake_mode(pros::MotorBrake::brake);
	arm_sensor.set_position(0);

	while (true) {

		levelPressed = controller.get_digital(pros::E_CONTROLLER_DIGITAL_X);

		if (levelPressed && !prevLevelState) {
			levelState = !levelState;
			level.set_value(levelState);
		}

		prevLevelState = levelPressed;

		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
			pto.set_value(true);
			pros::delay(100);
			intake.move(intake_speed);
		}
		else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
			pto.set_value(true);
			pros::delay(100);
			intake.move(-intake_speed);
		}
		else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
			pto.set_value(false);
			pros::delay(100);
			if (arm_sensor.get_position() < 13000) {intake.move(intake_speed);}
			else {intake.move(0);}
		}
		else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
			pto.set_value(false);
			pros::delay(100);
			if (arm_sensor.get_position() > 200) {intake.move(-intake_speed);}
			else {intake.move(0);}
		}
		else {
			pto.set_value(false);
			pros::delay(100);
			if (arm_sensor.get_position() > 200) {intake.move(-intake_speed);}
			else {intake.move(0);}
		}
		
    	// get left y and right x positions
    	int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    	int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

    	// move the robot
    	chassis.arcade(leftY, rightX);

		pros::delay(20);                               // Run for 20 ms then update
	}
}