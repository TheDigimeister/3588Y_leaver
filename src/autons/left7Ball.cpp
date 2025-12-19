#include "drive.hpp"
#include "main.h"
#include "utils.hpp"

// scoring
// pto.set_value(false);
// pros::delay(100);
// while (arm_sensor.get_position() < 13000) {intake.move(127);}
// while (arm_sensor.get_position() > 200) {intake.move(-127);}
// pto.set_value(true);
// pros::delay(100);
// intake.move(127);

void left7Ball(){
    
    // setup
    chassis.setPose(positionFromRaycast(back_dist.get()*MM_TO_IN, BACK_DIST_OFFSET, WEST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, NORTH), 90);
    level.set_value(true);
    pto.set_value(true);
    gate.set_value(false);
    descore.set_value(true);
    pros::delay(100);
    intake.move(127);

    // right7Ball

    // chassis.turnToPoint(-24, -24, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(-20, 25, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    pros::delay(500);
    matchload.set_value(true);
    chassis.turnToPoint(-50, 46, 1000, {.forwards=true, .maxSpeed=80}, true);
    chassis.moveToPoint(-50, 45, 1700, {.forwards=true, .maxSpeed=127}, true);
    matchload.set_value(true);
    chassis.turnToHeading(270, 1000, {.maxSpeed=80}, false);
    // chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    
    chassis.setPose(chassis.getPose().x, positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);

    chassis.moveToPoint(-65, 48, 1200, {.forwards=true, .maxSpeed=45, .minSpeed=45}, true);
    pros::delay(1200);
    // chassis.turnToPoint(-25, 48, 500, {.forwards=false, .maxSpeed=80}, true);
    chassis.moveToPoint(-25, 48, 2000, {.forwards=false, .maxSpeed=55}, false);
    pto.set_value(false);
    gate.set_value(true);
    pros::delay(200);
    intake.move(127);
    pros::delay(50);
    intake.move(64);
    pros::delay(800);
    intake.move(-127);
    pros::delay(200);
    pto.set_value(true);
    pros::delay(100);
    intake.move(127);
    gate.set_value(false);
    matchload.set_value(false);
    descore.set_value(false);

    chassis.turnToHeading(270, 500, {}, false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);

    left_mg.move(50);
    right_mg.move(50);
    pros::delay(200);
    chassis.turnToHeading(335, 500, {.maxSpeed=80}, false);
    left_mg.move(-50);
    right_mg.move(-50);
    pros::delay(400);
    chassis.turnToHeading(85, 1000, {.maxSpeed=127}, false);
    left_mg.move(127);
    right_mg.move(127);
    pros::delay(500);
    // chassis.moveToPose(-4, 36, 90, 2000, {.maxSpeed=127, .minSpeed=127});
    chassis.turnToHeading(90, 1000, {}, false);

}