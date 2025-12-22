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
    chassis.moveToPoint(-53, -46, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToHeading(270, 500, {}, false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);

    //matchload
    chassis.moveToPoint(-65, -47.5, 960, {.forwards=true, .maxSpeed=45, .minSpeed=45}, true);
    pros::delay(960);
    // chassis.turnToPoint(-25, -47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);

    //high goal
    chassis.moveToPoint(-25.3, -47.6, 2000, {.forwards=false, .maxSpeed=50}, false);
    pto.set_value(false);
    gate.set_value(true);
    pros::delay(200);
    intake.move(100);
    pros::delay(50);
    intake.move(60);
    pros::delay(800);
    intake.move(-127);
    pros::delay(200);
    pto.set_value(true);
    pros::delay(100);
    intake.move(127);
    gate.set_value(false);
    matchload.set_value(false);

    //low goal
    chassis.turnToPoint(-40.5, -47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.moveToPoint(-40.5, -47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToPoint(-22, -24, 2000, {.forwards=true, .maxSpeed=100, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.moveToPoint(-22, -24, 2000, {.forwards=true, .maxSpeed=90, .minSpeed=40, .earlyExitRange=5}, true);
    chassis.moveToPoint(-8, -9.7, 2000, {.forwards=true, .maxSpeed=40, .minSpeed=5, .earlyExitRange=5}, false);
    pros::delay(100);
    intake.move(-55);    
    pros::delay(1000);
    descore.set_value(false);
    pros::delay(100);
    intake.move(127);

    //descore
    chassis.turnToPoint(-34, -41.1, 2000, {.forwards=false, .maxSpeed=127,.minSpeed=5,.earlyExitRange=5}, true);
    chassis.moveToPoint(-34, -41.1, 2000, {.forwards=false, .maxSpeed=127}, true);
    chassis.turnToPoint(-6, -42, 2000, {.forwards=true, .maxSpeed=80}, true);
    chassis.moveToPoint(-6, -42, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToHeading(70, 2000, {}, false);

}