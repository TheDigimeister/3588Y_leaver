#include "drive.hpp"
#include "main.h"
#include "utils.hpp"

void rightLowGoal() {

    // setup

    chassis.setPose(positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, WEST), positionFromRaycast(fmax(front_dist.get(),front_disttwo.get())*MM_TO_IN, FRONT_DIST_OFFSET, SOUTH), 180);
    level.set_value(true);
    pto.set_value(false);
    gate.set_value(false);
    descore.set_value(true);
    pros::delay(100);
    intake.move(127);
    matchload.set_value(true);


    //to matchload

    // chassis.turnToPoint(-50, -47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.moveToPoint(-53, -44, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToHeading(270, 500, {}, false);
    chassis.setPose(positionFromRaycast(fmax(front_dist.get(),front_disttwo.get())*MM_TO_IN,FRONT_DIST_OFFSET,WEST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);


    //matchload

    chassis.moveToPoint(-65, -47.4, 1020, {.forwards=true, .maxSpeed=45, .minSpeed=45}, true);
    pros::delay(1020);
    // chassis.turnToPoint(-25, -47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);


    //high goal

    chassis.moveToPoint(-25.5, -47.6, 1500, {.forwards=false, .maxSpeed=70, .minSpeed=5}, true);
    matchload.set_value(false);
    pros::delay(100);
    intake.move(0);
    pros::delay(1400);
    pto.set_value(true);
    gate.set_value(true);
    pros::delay(200);
    intake.move(80);
    pros::delay(580);
    intake.move(-127);
    pros::delay(200);
    pto.set_value(false);
    pros::delay(100);
    intake.move(127);
    gate.set_value(false);


    //low goal

    // chassis.turnToPoint(-40.5, -47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    intake.move(-127);
    left_mg.move(127);
    right_mg.move(127);
    pros::delay(410);
    left_mg.move(0);
    right_mg.move(0);
    chassis.turnToHeading(270, 500, {}, false);
    chassis.setPose(positionFromRaycast(fmax(front_dist.get(),front_disttwo.get())*MM_TO_IN,FRONT_DIST_OFFSET,WEST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);

    chassis.turnToPoint(-24, -15, 2000, {.forwards=true, .maxSpeed=80, .minSpeed=5, .earlyExitRange=5}, true);
    intake.move(127);
    chassis.moveToPoint(-24, -15, 2000, {.forwards=true, .maxSpeed=90}, false);
    // chassis.moveToPoint(-19, -16, 2000, {.forwards=true, .maxSpeed=40}, false);
    // chassis.turnToPoint( 13.25, -13.25, 1000, {.forwards=true,.maxSpeed=80});
    left_mg.move(75);
    right_mg.move(75);
    pros::delay(240);
    left_mg.move(0);
    right_mg.move(0);
    pros::delay(100);
    intake.move(-40);
    intake_lift.set_value(true);
    pros::delay(1100);
    intake.move(127);


    //descore

    chassis.turnToPoint(-41, -41.7, 2000, {.forwards=false, .maxSpeed=127,.minSpeed=5,.earlyExitRange=5}, true);
    chassis.moveToPoint(-41, -41.7, 2000, {.forwards=false, .maxSpeed=127}, true);
    chassis.turnToPoint(-5, -41.5, 2000, {.forwards=true, .maxSpeed=70,.minSpeed=5}, false);
    descore.set_value(false);
    left_mg.move(90);
    right_mg.move(90);
    pros::delay(450);
    left_mg.move(0);
    right_mg.move(0);
    chassis.turnToHeading(75, 2000, {}, false);

}