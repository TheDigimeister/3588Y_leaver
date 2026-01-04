#include "drive.hpp"
#include "main.h"
#include "utils.hpp"

void sigawp() {


    // setup

    chassis.setPose(positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, WEST), positionFromRaycast(back_dist.get()*MM_TO_IN, BACK_DIST_OFFSET, SOUTH), 0);
    level.set_value(true);
    pto.set_value(false);
    gate.set_value(false);
    descore.set_value(true);
    pros::delay(100);
    intake.move(127);
    matchload.set_value(false);
    

    //push other robor

    left_mg.move(90);
    right_mg.move(90);
    pros::delay(230);


    //go to matchload

    chassis.moveToPoint(-49, -47.5, 1300, {.forwards=false, .maxSpeed=127, .minSpeed=127, .earlyExitRange=5}, true);
    chassis.moveToPoint(-49, -47.5, 2000, {.forwards=false, .maxSpeed=80, .minSpeed=80, .earlyExitRange=5}, true);
    matchload.set_value(true);
    chassis.turnToHeading(270, 500, {}, false);
    chassis.setPose(positionFromRaycast(fmax(front_dist.get(),front_disttwo.get())*MM_TO_IN,FRONT_DIST_OFFSET,WEST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);


    //go in matchload

    chassis.moveToPoint(-65, -49, 1150, {.forwards=true, .maxSpeed=55, .minSpeed=55}, true);
    pros::delay(1160);


    //go to score

    chassis.moveToPoint(-31, -51, 600, {.forwards=false, .maxSpeed=127, .minSpeed=127}, true);
    chassis.moveToPoint(-31, -51, 600, {.forwards=false, .maxSpeed=70, .minSpeed=70}, false);
    matchload.set_value(false);
    pto.set_value(true);
    gate.set_value(true);
    intake.move(90);
    pros::delay(520);
    intake.move(-127);
    pros::delay(200);
    pto.set_value(false);
    intake.move(127);
    gate.set_value(false);


    //go to triple balls lower goal

    chassis.moveToPoint(-42, -48, 1000, {.forwards=true,.maxSpeed=127,.minSpeed=80,.earlyExitRange=5},false);
    chassis.setPose(positionFromRaycast(fmax(front_dist.get(),front_disttwo.get())*MM_TO_IN,FRONT_DIST_OFFSET,WEST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);
    chassis.turnToPoint(-24, -24, 1000, {.forwards=true,.maxSpeed=100,.minSpeed=5},true);
    chassis.moveToPoint(-24, -24, 1000, {.forwards=true,.maxSpeed=127,.minSpeed=127,.earlyExitRange=5},false);
    level.set_value(false);
    matchload.set_value(true);

    
    //go to triple balls middle goal

    chassis.turnToHeading(0, 1000, {.maxSpeed=127,.minSpeed=100,.earlyExitRange=5},false);
    chassis.setPose(positionFromRaycast(left_dist.get()*MM_TO_IN,LEFT_DIST_OFFSET,WEST), positionFromRaycast(back_dist.get()*MM_TO_IN, BACK_DIST_OFFSET, SOUTH), chassis.getPose().theta);
    chassis.moveToPoint(-28, 23, 900, {.forwards=true,.maxSpeed=127,.minSpeed=127},true);
    pros::delay(300);
    matchload.set_value(false);
    chassis.moveToPoint(-28, 23, 650, {.forwards=true,.maxSpeed=70,.minSpeed=40},true);
    pros::delay(250);
    matchload.set_value(true);
    left_mg.move(-70);
    right_mg.move(-70);
    pros::delay(100);
    chassis.turnToHeading(315, 2000,{.maxSpeed=80,.minSpeed=10},false);


    //score middle goal

    chassis.moveToPoint(-18, 14, 2000, {.forwards=false,.maxSpeed=105,.minSpeed=10},false);
    gate.set_value(true);
    pros::delay(1000);
    

    //score long goal

    chassis.moveToPoint(-42, 39.5, 1000, {.forwards=true,.maxSpeed=127,.minSpeed=100},true);
    pros::delay(100);
    gate.set_value(true);
    matchload.set_value(false);
    level.set_value(true);
    chassis.moveToPoint(-42, 39.5, 2000, {.forwards=true,.maxSpeed=70,.minSpeed=70},true);
    chassis.turnToHeading(270, 2000, {.maxSpeed=80,.minSpeed=10},false);
    chassis.setPose(positionFromRaycast(fmax(front_dist.get(),front_disttwo.get())*MM_TO_IN,FRONT_DIST_OFFSET,WEST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    chassis.moveToPoint(-30, 47.6, 1000, {.forwards=false, .maxSpeed=127, .minSpeed=5}, false);
    intake.move(0);
    pto.set_value(true);
    gate.set_value(true);
    intake.move(90);
    pros::delay(520);
    intake.move(-127);
    pros::delay(200);
    pto.set_value(false);
    intake.move(127);
    gate.set_value(false);
}