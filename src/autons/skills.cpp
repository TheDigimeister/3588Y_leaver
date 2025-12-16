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

void skills() {
    
    // setup
    chassis.setPose(positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, WEST), positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, NORTH), 0);
    level.set_value(true);
    pto.set_value(true);
    pros::delay(100);
    intake.move(127);

    // drive through west parking
    left_mg.move(80);
    right_mg.move(80);
    pros::delay(1500);

    // reset after west parking
    chassis.turnToHeading(90, 1000, {}, false);
    chassis.setPose(positionFromRaycast(back_dist.get()*MM_TO_IN, BACK_DIST_OFFSET, WEST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, NORTH), chassis.getPose().theta);

    // middle goal score
    chassis.turnToPoint(-33, 24, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(-33, 24, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    // chassis.turnToPoint(-10, 10, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.turnToHeading(315, 1000, {}, false);
    level.set_value(false);
    // chassis.moveToPoint(-10, 10, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    left_mg.move(-50);
    right_mg.move(-50);
    pros::delay(550);
    left_mg.move(0);
    right_mg.move(0);
    pto.set_value(false);
    pros::delay(100);
    while (arm_sensor.get_position() < 13000) {intake.move(127);}
    while (arm_sensor.get_position() > 200) {intake.move(-127);}
    pto.set_value(true);
    level.set_value(true);
    pros::delay(100);
    intake.move(127);
    
    // NW matchload
    matchload.set_value(true);
    left_mg.move(127);
    right_mg.move(127);
    pros::delay(700);
    // chassis.turnToPoint(-48, 47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    // chassis.moveToPoint(-48, 47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.turnToHeading(270, 500, {}, false);
    // chassis.turnToPoint(-62, 47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    chassis.moveToPoint(-62, 47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    
    // NE long goal score
    chassis.turnToPoint(-24, 64, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(-24, 64, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.turnToPoint(30, 64, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    matchload.set_value(false);
    chassis.moveToPoint(30, 64, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.turnToPoint(48, 47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(48, 47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    
    chassis.turnToHeading(90, 1000, {}, false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, EAST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    chassis.moveToPoint(26, 47, 2000, {.forwards=false, .maxSpeed=70, .minSpeed=5, .earlyExitRange=1}, false);
    pto.set_value(false);
    pros::delay(100);
    while (arm_sensor.get_position() < 13000) {intake.move(127);}
    while (arm_sensor.get_position() > 200) {intake.move(-127);}
    pto.set_value(true);
    pros::delay(100);
    intake.move(127);

    // NE matchload
    matchload.set_value(true);
    chassis.turnToPoint(62, 47, 2000, {.forwards=true, .maxSpeed=45, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(62, 47, 2000, {.forwards=true, .maxSpeed=45, .minSpeed=5, .earlyExitRange=1}, true);
    
    // NE long goal score again
    chassis.turnToPoint(25, 47, 2000, {.forwards=false, .maxSpeed=70, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(25, 47, 2000, {.forwards=false, .maxSpeed=70, .minSpeed=5, .earlyExitRange=1}, false);
    pto.set_value(false);
    pros::delay(100);
    while (arm_sensor.get_position() < 13000) {intake.move(127);}
    while (arm_sensor.get_position() > 200) {intake.move(-127);}
    pto.set_value(true);
    pros::delay(100);
    intake.move(127);
    
    // drive through east parking
    matchload.set_value(false);
    chassis.turnToPoint(64, 21, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(64, 21, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);

    chassis.turnToHeading(160, 500, {}, false);
    
    left_mg.move(100);
    right_mg.move(100);
    pros::delay(2000);

    chassis.turnToHeading(90, 1000, {}, false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, EAST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, SOUTH), chassis.getPose().theta);
    
    // SE long goal score
    // chassis.turnToPoint(48, -18, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    // chassis.moveToPoint(48, -18, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.turnToPoint(48, -47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(48, -47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.turnToPoint(25, -47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(25, -47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, false);
    pto.set_value(false);
    pros::delay(100);
    while (arm_sensor.get_position() < 13000) {intake.move(127);}
    while (arm_sensor.get_position() > 200) {intake.move(-127);}
    pto.set_value(true);
    pros::delay(100);
    intake.move(127);
    
    // SE matchload
    matchload.set_value(true);
    chassis.turnToPoint(62, -47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(62, -47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    
    // SW long goal score
    chassis.turnToPoint(24, -60, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(24, -60, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.turnToPoint(-24, -60, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    matchload.set_value(false);
    chassis.moveToPoint(-24, -60, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.turnToPoint(-48, -47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(-48, -47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.turnToPoint(-25, -47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(-25, -47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, false);
    pto.set_value(false);
    pros::delay(100);
    while (arm_sensor.get_position() < 13000) {intake.move(127);}
    while (arm_sensor.get_position() > 200) {intake.move(-127);}
    pto.set_value(true);
    pros::delay(100);
    intake.move(127);
    
    // SE matchload
    matchload.set_value(true);
    chassis.turnToPoint(-62, -47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(-62, -47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    
    // SE long goal score again
    chassis.turnToPoint(-25, -47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(-25, -47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, false);
    pto.set_value(false);
    pros::delay(100);
    while (arm_sensor.get_position() < 13000) {intake.move(127);}
    while (arm_sensor.get_position() > 200) {intake.move(-127);}
    pto.set_value(true);
    pros::delay(100);
    intake.move(127);
    
    // park in west parking
    matchload.set_value(false);
    chassis.turnToPoint(-62, -18, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(-62, -18, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);

    chassis.turnToHeading(345, 500, {}, false);
    left_mg.move(80);
    right_mg.move(80);
    pros::delay(1000);
    left_mg.move(0);
    right_mg.move(0);

}