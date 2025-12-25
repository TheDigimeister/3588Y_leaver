#include "drive.hpp"
#include "main.h"
#include "pros/rtos.hpp"
#include "utils.hpp"

void testing(){

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
    chassis.turnToPoint(-22.7, 24, 2000, {.forwards=true, .maxSpeed=80, .minSpeed=5},true);
    chassis.moveToPoint(-22.7, 24, 2000, {.forwards=true, .maxSpeed=60},false);


    //turn around to middle goal
    chassis.turnToHeading(315, 2000, {.maxSpeed=80}, false);

    left_mg.move(-70);
    right_mg.move(-70);
    pros::delay(600);
    left_mg.move(0);
    right_mg.move(0);


    //score
    
    pto.set_value(true);
    gate.set_value(true);
    intake.move(0);
    pros::delay(200);
    intake.move(40);
    pros::delay(50);
    intake.move(30);
    pros::delay(1000);
    intake.move(-127);
    pros::delay(200);
    intake.move(0);

    
    //goes next to matchload

    chassis.moveToPoint(-44, 46, 2000, {.forwards=true, .maxSpeed=127}, true);
    chassis.waitUntil(10);
    intake.move(127);
    pros::delay(200);
    intake.move(-127);
    pros::delay(200);
    intake.move(0);
    pto.set_value(false);
    gate.set_value(false);
    matchload.set_value(true);
    level.set_value(true);
    pros::delay(100);
    chassis.turnToHeading(270, 2000, {.maxSpeed=70},false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);


    //goes inside matchload

    intake.move(127);
    chassis.turnToPoint(-65, 49, 1000, {.forwards=true, .maxSpeed=80, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.moveToPoint(-65, 49, 2800, {.forwards=true, .maxSpeed=55}, true);
    pros::delay(2800);


    //going to score

    chassis.moveToPoint(-25, 63, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=127},true);
    chassis.waitUntil(10);
    matchload.set_value(false);
    pto.set_value(false);
    intake.move(0);
    pros::delay(100);
    chassis.moveToPoint(42, 60, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=127, .earlyExitRange=5}, false);
    chassis.turnToHeading(270, 2000, {.maxSpeed=80}, false);
    chassis.setPose(positionFromRaycast(back_dist.get()*MM_TO_IN, BACK_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, SOUTH), chassis.getPose().theta);
    chassis.moveToPose(34, 27, 270, 2000, {.forwards=false,.maxSpeed=127}, true);


    //scoring


}