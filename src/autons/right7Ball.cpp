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

void right7Ball(){
    
    // setup
    chassis.setPose(positionFromRaycast(back_dist.get()*MM_TO_IN, BACK_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, SOUTH), 90);
    level.set_value(true);
    pto.set_value(true);
    gate.set_value(false);
    descore.set_value(true);
    pros::delay(100);
    intake.move(127);

    // right7Ball

    // chassis.turnToPoint(-24, -24, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(-17, -27, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    pros::delay(500);
    matchload.set_value(true);
    chassis.turnToPoint(-48, -46, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(-48, -46, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=4}, true);
    matchload.set_value(true);
    chassis.turnToHeading(270, 1000, {.maxSpeed=80}, false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);
    
    chassis.moveToPoint(-65, -48, 1100, {.forwards=true, .maxSpeed=45, .minSpeed=45}, true);
    pros::delay(1100);
    // chassis.turnToPoint(-25, -48, 2000, {.forwards=false, .maxSpeed=80}, true);
    chassis.moveToPoint(-25, -48, 2000, {.forwards=false, .maxSpeed=55}, false);
    pto.set_value(false);
    gate.set_value(true);
    pros::delay(200);
    intake.move(127);
    pros::delay(50);
    intake.move(80);
    //intake speed was 64
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
    chassis.setPose(chassis.getPose().x, positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);

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