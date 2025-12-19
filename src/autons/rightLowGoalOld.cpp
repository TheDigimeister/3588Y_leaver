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

void rightLowGoalOld(){
    
    // setup
    chassis.setPose(positionFromRaycast(back_dist.get()*MM_TO_IN, BACK_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), 90);
    level.set_value(true);
    pto.set_value(true);
    gate.set_value(false);
    pros::delay(100);
    intake.move(127);
    
    // rightLowGoal

    chassis.turnToPoint(-24, -24, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    pros::delay(500);
    matchload.set_value(true);
    chassis.moveToPoint(-24, -24, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);

    chassis.turnToHeading(45, 1000, {}, false);
    matchload.set_value(false);
    left_mg.move(50);
    right_mg.move(50);
    pros::delay(550);
    left_mg.move(0);
    right_mg.move(0);
    pto.set_value(true);
    pros::delay(100);
    intake.move(-127);    
    pros::delay(1000);
    pto.set_value(true);
    pros::delay(100);
    intake.move(127);

    chassis.turnToPoint(-48, -47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(-48, -47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    
    chassis.turnToHeading(270, 1000, {}, false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);
    
    chassis.moveToPoint(-62, -47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToPoint(-25, -47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(-25, -47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, false);
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

    chassis.turnToHeading(270, 500, {}, false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, NORTH), chassis.getPose().theta);

    left_mg.move(50);
    right_mg.move(50);
    pros::delay(200);
    chassis.turnToHeading(200, 500, {.maxSpeed=80}, false);
    left_mg.move(-50);
    right_mg.move(-50);
    pros::delay(400);
    chassis.turnToHeading(90, 1000, {.maxSpeed=127}, false);
    left_mg.move(50);
    right_mg.move(50);
    pros::delay(1100);
    chassis.turnToHeading(90, 1000, {}, false);
}