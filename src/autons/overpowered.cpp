#include "drive.hpp"
#include "main.h"
#include "pros/rtos.hpp"
#include "utils.hpp"

void overpwed(){

    //starting position is same place as 15 sec auto place
    // setup
    chassis.setPose(positionFromRaycast(back_dist.get()*MM_TO_IN, BACK_DIST_OFFSET, WEST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, NORTH), 90);
    level.set_value(false);
    pto.set_value(false);
    descore.set_value(true);
    gate.set_value(false);
    pros::delay(100);
    intake.move(127);


    //get the four balls
    // chassis.turnToPoint(-23, 24, 500, {.forwards=true, .maxSpeed=90, .minSpeed=5},true);
    chassis.moveToPoint(-23, 23.9, 2000, {.forwards=true, .maxSpeed=80},false);
    
    left_mg.move(-50);
    right_mg.move(-50);
    pros::delay(60);


    //turn around to middle goal
    chassis.turnToHeading(315, 700, {.maxSpeed=80,.minSpeed=5},false);

    left_mg.move(-80);
    right_mg.move(-80);
    pros::delay(520);
    left_mg.move(0);
    right_mg.move(0);


    //score middle goal balls
    
    pto.set_value(true);
    gate.set_value(true);
    intake.move(0);
    pros::delay(200);
    intake.move(45);
    pros::delay(950);
    intake.move(-127);
    pros::delay(200);
    intake.move(0);

    
    //goes to matchload #1

    // chassis.moveToPoint(-53, 47.6, 1500, {.forwards=true, .maxSpeed=85}, true);
    chassis.moveToPoint(-50, 44, 1500, {.forwards=true, .maxSpeed=85}, true);
    chassis.waitUntil(8);
    intake.move(0);
    pto.set_value(false);
    gate.set_value(false);
    matchload.set_value(true);
    level.set_value(true);
    pros::delay(1290);
    intake.move(127);
    chassis.turnToHeading(270, 2000, {.maxSpeed=70},false);
    chassis.setPose(positionFromRaycast(fmax(front_disttwo.get(),front_dist.get())*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    
    
    
    //goes inside matchload #1

    intake.move(127);
    chassis.moveToPoint(-67, 48.5, 2200, {.forwards=true, .maxSpeed=127,.minSpeed=50}, true);
    pros::delay(2200);


    //going to score

    chassis.moveToPoint(-25, 61.5, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=127},true);
    chassis.waitUntil(10);
    matchload.set_value(false);
    pto.set_value(true);
    intake.move(0);
    pros::delay(100);
    chassis.moveToPoint(28, 59, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=127, .earlyExitRange=5}, true);
    
    // chassis.turnToHeading(0, 2000, {.maxSpeed=80}, true);
    // chassis.moveToPoint(26, 46, 2000, {.forwards=false,.maxSpeed=100},true);
    // chassis.turnToHeading(90, 2000, {.maxSpeed=70},false);

    chassis.moveToPose(45, 53, 90, 5000, {.forwards=true,.maxSpeed=110,.minSpeed=35},true);
    chassis.turnToHeading(90, 2000, {.maxSpeed=80,.minSpeed=7},false);

    chassis.setPose(positionFromRaycast(fmax(front_dist.get(),front_disttwo.get())*MM_TO_IN, FRONT_DIST_OFFSET, EAST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    

    //scoring #1

    chassis.moveToPoint(29, 50, 650, {.forwards=false, .maxSpeed=75}, false);
    gate.set_value(true);
    pros::delay(200);
    intake.move(100);
    pros::delay(120);
    intake.move(52);
    pros::delay(860);
    intake.move(-127);
    pros::delay(200);
    pto.set_value(false);
    gate.set_value(false);
    matchload.set_value(true);
    pros::delay(100);
    intake.move(127);

    
    //matchload #2

    chassis.moveToPoint(65, 47.88, 2800, {.forwards=true, .maxSpeed=90,.minSpeed=10}, true);
    pros::delay(2800);


    //scoring #2
    
    chassis.moveToPoint(29, 50, 1400, {.forwards=false, .maxSpeed=75}, false);
    pto.set_value(true);
    gate.set_value(true);
    intake.move(0);
    pros::delay(200);
    intake.move(95);
    pros::delay(80);
    intake.move(50);
    pros::delay(960);
    intake.move(-127);
    pros::delay(200);
    intake.move(0);
    matchload.set_value(false);
    // matchload.set_value(false);


    //clear parking

    chassis.moveToPose(68, 14, 180, 1500, {.forwards=true, .maxSpeed=127, .minSpeed=127},true);
    pros::delay(500);
    gate.set_value(false);
    pto.set_value(false);
    pros::delay(500);
    intake.move(127);
    level.set_value(false);
    pros::delay(500);


    left_mg.move(62);
    right_mg.move(62);
    pros::delay(3030);
    left_mg.move(0);
    right_mg.move(0);


    //spin to middle again for scoring

    chassis.turnToHeading(270, 2000, {.maxSpeed=80},false);
    intake.move(0);
    pto.set_value(true);
    chassis.setPose(positionFromRaycast(back_dist.get()*MM_TO_IN, BACK_DIST_OFFSET, EAST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);
    chassis.moveToPoint(29.3, -32, 2000, {.forwards=true, .maxSpeed=90},true);
    chassis.turnToHeading(135.45, 2000, {.maxSpeed=75,.minSpeed=5},false);
    
    left_mg.move(-100);
    right_mg.move(-100);
    pros::delay(500);
    left_mg.move(-60);
    right_mg.move(-60);
    pros::delay(230);
    left_mg.move(0);
    right_mg.move(0);


    //middle goal score #2

    gate.set_value(true);
    int cnt=0;
	pros::delay(500);
	intake.move(35);
	pros::delay(860);
    intake.move(-127);
    pros::delay(110);
	while(arm_sensor.get_position()<11800){
		intake.move(26);
		cnt++;
		pros::delay(15);
		if(cnt>115)
		{
			break;
		}
	}
	intake.move(-127);
    pros::delay(250);
    intake.move(0);
    pto.set_value(false);


    //going near matchload #3

    // chassis.moveToPoint(48, -46.5, 2000, {.forwards=true, .maxSpeed=100}, true);
    chassis.moveToPoint(48, -45.5, 2000, {.forwards=true, .maxSpeed=100}, true);
    chassis.waitUntil(10);
    gate.set_value(false);
    matchload.set_value(true);
    level.set_value(true);
    intake.move(127);
    chassis.turnToHeading(90, 2000, {.maxSpeed=85},false);
    chassis.setPose(positionFromRaycast(fmax(front_dist.get(),front_disttwo.get())*MM_TO_IN, FRONT_DIST_OFFSET, EAST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, SOUTH), chassis.getPose().theta);


    //going into matchload #3
    
    // chassis.turnToPoint(65, -48.4, 1000, {.forwards=true, .maxSpeed=80}, true);
    chassis.moveToPoint(65, -48.2, 1900, {.forwards=true, .maxSpeed=127,.minSpeed=55}, true);
    pros::delay(1900);


    //going to score #3

    chassis.moveToPoint(29.5, -64, 2000, {.forwards=false,.maxSpeed=127,.minSpeed=127,.earlyExitRange=5},true);

    chassis.moveToPoint(-25, -63, 2000, {.forwards=false,.maxSpeed=127,.minSpeed=127},true);
    intake.move(0);
    chassis.waitUntil(10);
    matchload.set_value(false);
    pto.set_value(true);
    // chassis.turnToHeading(180, 2000, {.maxSpeed=80,.minSpeed=5,.earlyExitRange=0.5},false);
    // chassis.moveToPoint(-26, -43, 2000,{.forwards=false,.maxSpeed=100,.minSpeed=5},false);
    // left_mg.move(-90);
    // right_mg.move(-90);
    // pros::delay(200);
    // chassis.turnToHeading(270, 2000,{.maxSpeed=80,.minSpeed=5},false);

    chassis.moveToPose(-46, -57.5, 270, 3000, {.forwards=true,.maxSpeed=110,.minSpeed=30},true);
    chassis.turnToHeading(270, 2000, {.maxSpeed=75,.minSpeed=2},false);

    chassis.setPose(positionFromRaycast(fmax(front_dist.get(),front_disttwo.get())*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);


    //score #3

    chassis.moveToPoint(-29, -49.5, 800, {.forwards=false, .maxSpeed=75}, false);
    gate.set_value(true);
    pros::delay(100);
    intake.move(90);
    pros::delay(80);
    intake.move(50);
    pros::delay(950);
    intake.move(-127);
    pros::delay(250);
    pto.set_value(false);
    pros::delay(100);
    gate.set_value(false);
    intake.move(127);
    matchload.set_value(true);


    //matchload #4

    chassis.moveToPoint(-64.5, -47.88, 1500, {.forwards=true, .maxSpeed=65}, false);
    pros::delay(1500);

    
    //scoring #4

    chassis.moveToPoint(-28.5, -49.5, 1600, {.forwards=false, .maxSpeed=80},false);
    pto.set_value(true);
    matchload.set_value(false);
    gate.set_value(true);
    intake.move(0);
    pros::delay(300);
    intake.move(100);
    pros::delay(80);
    intake.move(55);
    pros::delay(980);
    intake.move(-127);
    pros::delay(250);
    intake.move(0);
    pto.set_value(false);


    //low goal for 100 points

    chassis.moveToPoint(-43, -48, 2000,{.forwards=true, .maxSpeed=127,.minSpeed=127},true);
    chassis.turnToHeading(270, 500, {}, false);
    chassis.setPose(positionFromRaycast(fmax(front_dist.get(),front_disttwo.get())*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);

    chassis.turnToHeading(50.2, 2000, {.maxSpeed=90},false);
    
    
    //get 4 cross balls

    left_mg.move(90);
    right_mg.move(90);
    intake.move(127);
    pros::delay(850);


    //aim for the center

    left_mg.move(40);
    right_mg.move(40);
    pros::delay(970);
    left_mg.move(0);
    right_mg.move(0);
    pros::delay(200);
    intake.move(-55);    
    pros::delay(2000);


    //turn around to park

    left_mg.move(-78);
    right_mg.move(-127);
    pros::delay(100);
    intake.move(-127);
    pros::delay(1100);
    chassis.turnToHeading(345, 2000, {.maxSpeed=80,.minSpeed=15},false);


    // //PARK PARK PARK PARK PARK PARK PARK PARK PARK PARK PARK PARK PARK PARK PARK PARK PARK

    left_mg.move(127);
    right_mg.move(127);
    pros::delay(520);
    left_mg.move(70);
    right_mg.move(70);
    pros::delay(980);
    left_mg.move(0);
    right_mg.move(0);
}