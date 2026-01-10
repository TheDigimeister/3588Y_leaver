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
    chassis.moveToPoint(-23, 23.9, 2000, {.forwards=true, .maxSpeed=85},false);
    
    left_mg.move(-50);
    right_mg.move(-50);
    pros::delay(55);


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

    chassis.moveToPoint(-54.2, 45, 1500, {.forwards=true, .maxSpeed=85}, true);
    chassis.waitUntil(8);
    intake.move(0);
    pto.set_value(false);
    gate.set_value(false);
    matchload.set_value(true);
    level.set_value(true);
    pros::delay(1290);
    intake.move(127);
    chassis.turnToHeading(270, 800, {.maxSpeed=70,.minSpeed=5},false);
    chassis.setPose(positionFromRaycast(fmax(front_disttwo.get(),front_dist.get())*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    
    
    
    //goes inside matchload #1

    intake.move(127);
    chassis.moveToPoint(-67, 48.79, 1000, {.forwards=true, .maxSpeed=127,.minSpeed=50}, true);
    pros::delay(2600);


    //going to score

    chassis.moveToPoint(-27, 62, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=127},true);
    chassis.waitUntil(10);
    matchload.set_value(false);
    pto.set_value(true);
    intake.move(0);
    pros::delay(100);
    chassis.moveToPoint(28, 59, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=127, .earlyExitRange=5}, true);
    
    // chassis.turnToHeading(0, 2000, {.maxSpeed=80}, true);
    // chassis.moveToPoint(26, 46, 2000, {.forwards=false,.maxSpeed=100},true);
    // chassis.turnToHeading(90, 2000, {.maxSpeed=70},false);

    chassis.moveToPose(44, 53, 90, 5000, {.forwards=true,.maxSpeed=110,.minSpeed=35},true);
    chassis.turnToHeading(90, 2000, {.maxSpeed=80,.minSpeed=7},false);

    chassis.setPose(positionFromRaycast(fmax(front_dist.get(),front_disttwo.get())*MM_TO_IN, FRONT_DIST_OFFSET, EAST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    

    //scoring #1

    chassis.moveToPoint(29, 50, 650, {.forwards=false, .maxSpeed=75}, false);
    gate.set_value(true);
    pros::delay(200);
    intake.move(100);
    pros::delay(150);
    intake.move(52);
    pros::delay(750);
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
    pros::delay(120);
    intake.move(46);
    pros::delay(855);
    intake.move(-127);
    pros::delay(200);
    intake.move(0);
    matchload.set_value(false);
    // matchload.set_value(false);


    //clear parking

    chassis.moveToPose(68, 13.9, 175, 1500, {.forwards=true, .maxSpeed=127, .minSpeed=127},true);
    pros::delay(500);
    gate.set_value(false);
    pto.set_value(false);
    pros::delay(500);
    intake.move(127);
    level.set_value(false);
    pros::delay(500);

    while(true)
    {
        if(front_dist.get()<=770)
        {
            left_mg.move(0);
            right_mg.move(0);
            break;
        }
        else 
        {
            left_mg.move(60);
            right_mg.move(60);
        }
        pros::delay(5);
    }


    //spin to middle again for scoring

    chassis.turnToHeading(270, 2000, {.maxSpeed=80},false);
    chassis.setPose(positionFromRaycast(back_dist.get()*MM_TO_IN, BACK_DIST_OFFSET, EAST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);
    chassis.moveToPoint(29.35, -32, 2000, {.forwards=true, .maxSpeed=90},true);
    chassis.waitUntil(15);
    intake.move(0);
    chassis.turnToHeading(135.4, 2000, {.maxSpeed=75,.minSpeed=5},false);
    
    left_mg.move(-100);
    right_mg.move(-100);
    pros::delay(535);
    pto.set_value(true);
    left_mg.move(-60);
    right_mg.move(-60);
    pros::delay(230);
    left_mg.move(0);
    right_mg.move(0);


    //middle goal score #2

    gate.set_value(true);
    int cnt=0;
	pros::delay(500);
	intake.move(41);
	pros::delay(870);
    intake.move(-127);
    pros::delay(110);
	while(arm_sensor.get_position()<11770){
		intake.move(26);
		cnt++;
		pros::delay(15);
		if(cnt>105)
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
    chassis.moveToPoint(48, -45.75, 2000, {.forwards=true, .maxSpeed=100}, true);
    chassis.waitUntil(10);
    gate.set_value(false);
    matchload.set_value(true);
    level.set_value(true);
    intake.move(127);
    chassis.turnToHeading(90, 2000, {.maxSpeed=85,.minSpeed=5},false);
    chassis.setPose(positionFromRaycast(fmax(front_dist.get(),front_disttwo.get())*MM_TO_IN, FRONT_DIST_OFFSET, EAST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, SOUTH), chassis.getPose().theta);


    //going into matchload #3
    
    // chassis.turnToPoint(65, -48.4, 1000, {.forwards=true, .maxSpeed=80}, true);
    chassis.moveToPoint(67, -48.5, 2000, {.forwards=true, .maxSpeed=127,.minSpeed=55}, true);
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

    chassis.moveToPose(-44, -55, 270, 3000, {.forwards=true,.maxSpeed=110,.minSpeed=30},true);
    chassis.turnToHeading(270, 2000, {.maxSpeed=75,.minSpeed=2},false);

    chassis.setPose(positionFromRaycast(fmax(front_dist.get(),front_disttwo.get())*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);


    //score #3

    chassis.moveToPoint(-29, -51, 800, {.forwards=false, .maxSpeed=75}, false);
    gate.set_value(true);
    pros::delay(100);
    intake.move(90);
    pros::delay(110);
    intake.move(50);
    pros::delay(860);
    intake.move(-127);
    pros::delay(250);
    pto.set_value(false);
    pros::delay(100);
    gate.set_value(false);
    intake.move(127);
    matchload.set_value(true);


    //matchload #4

    chassis.moveToPoint(-64.5, -47.85, 1500, {.forwards=true, .maxSpeed=65}, false);
    pros::delay(1500);

    
    //scoring #4

    chassis.moveToPoint(-28.5, -51, 300, {.forwards=false, .maxSpeed=100},true);
    chassis.moveToPoint(-28.5, -51, 1600, {.forwards=false,.maxSpeed=80},false);
    pto.set_value(true);
    matchload.set_value(false);
    gate.set_value(true);
    intake.move(0);

    pros::delay(200);
    intake.move(95);
    pros::delay(120);
    intake.move(46);
    pros::delay(855);
    intake.move(-127);
    pros::delay(220);

    // intake.move(100);
    // pros::delay(150);
    // intake.move(55);
    // pros::delay(800);
    // intake.move(-127);
    // pros::delay(250);
    intake.move(0);
    pto.set_value(false);


    //low goal for 100 points

    chassis.moveToPoint(-41, -48, 2000,{.forwards=true, .maxSpeed=127,.minSpeed=127},true);
    chassis.turnToHeading(270, 500, {}, false);
    chassis.setPose(positionFromRaycast(fmax(front_dist.get(),front_disttwo.get())*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);

    chassis.turnToHeading(47, 2000, {.maxSpeed=90},false);
    
    
    //get 4 cross balls

    left_mg.move(90);
    right_mg.move(90);
    intake.move(127);
    pros::delay(830);


    //aim for the center

    left_mg.move(60);
    right_mg.move(60);
    pros::delay(600);
    intake_lift.set_value(true);
    pros::delay(170);
    left_mg.move(0);
    right_mg.move(0);
    pros::delay(200);


    //score center

    intake.move(-40);
    left_mg.move(-50);
    right_mg.move(-50);
    pros::delay(150);
    left_mg.move(50);
    right_mg.move(50);
    pros::delay(210);
    left_mg.move(0);
    right_mg.move(0);
    pros::delay(1500);


    //turn around to park

    left_mg.move(-76);
    right_mg.move(-127);
    pros::delay(110);
    intake.move(-127);
    pros::delay(1150);
    chassis.turnToHeading(342, 2000, {.maxSpeed=80,.minSpeed=15},false);


    // //PARK PARK PARK PARK PARK PARK PARK PARK PARK PARK PARK PARK PARK PARK PARK PARK PARK

    left_mg.move(88);
    right_mg.move(120);
    pros::delay(520);
    intake_lift.set_value(false);
    while(true)
    {
        if(front_dist.get()>=1625&&front_dist.get()<=1670)
        {
            left_mg.move(0);
            right_mg.move(0);
            break;
        }
        else 
        {
            left_mg.move(70);
            right_mg.move(70);
        }
        pros::delay(5);
    }
}