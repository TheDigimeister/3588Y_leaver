#include "drive.hpp"
#include "main.h"
#include "utils.hpp"

void rightLowGoal() {

        // setup
    chassis.setPose(positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, WEST), positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, SOUTH), 180);
    level.set_value(true);
    pto.set_value(true);
    gate.set_value(false);
    descore.set_value(true);
    pros::delay(100);
    intake.move(127);
    matchload.set_value(true);


    //to matchload
    // chassis.turnToPoint(-50, -47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.moveToPoint(-53, -47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToHeading(270, 500, {}, false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);

    //matchload
    chassis.moveToPoint(-65, -47, 1100, {.forwards=true, .maxSpeed=45, .minSpeed=45}, true);
    pros::delay(1100);
    // chassis.turnToPoint(-25, -47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);

    //high goal
    chassis.moveToPoint(-25, -47, 2000, {.forwards=false, .maxSpeed=45}, false);
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

    //low goal
    chassis.turnToPoint(-41, -47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.moveToPoint(-41, -47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToPoint(-24, -24, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.moveToPoint(-24, -24, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=40, .earlyExitRange=5}, true);
    chassis.moveToPoint(-10.2, -10.2, 2000, {.forwards=true, .maxSpeed=40, .minSpeed=5, .earlyExitRange=5}, false);
    pto.set_value(true);
    pros::delay(100);
    intake.move(-127);    
    pros::delay(1000);
    pto.set_value(true);
    pros::delay(100);
    intake.move(127);

    //descore
    chassis.turnToPoint(-34, -33, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.moveToPoint(-34, -33, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToPoint(-5, -40, 2000, {.forwards=true, .maxSpeed=80}, true);
    chassis.moveToPoint(-5, -40, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);

}