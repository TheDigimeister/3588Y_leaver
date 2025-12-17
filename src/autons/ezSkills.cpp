#include "drive.hpp"
#include "main.h"
#include "utils.hpp"

void ezSkills(){

    // setup
    chassis.setPose(positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, WEST), positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, SOUTH), 180);
    level.set_value(true);
    pto.set_value(true);
    pros::delay(100);
    intake.move(127);

    // SW matchload
    matchload.set_value(true);
    chassis.moveToPoint(-47, -47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);

    chassis.turnToHeading(270, 1000, {}, false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);

    chassis.moveToPoint(-64, -48.25, 2000, {.forwards=true, .maxSpeed=55}, true);
    pros::delay(2000);
    
    // SE long goal score
    chassis.turnToPoint(-24, -64, 1000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(-24, -64, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToPoint(30, -64, 1000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    matchload.set_value(false);
    chassis.moveToPoint(30, -64, 3000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToPoint(47, -50, 1000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(47, -50, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    
    chassis.turnToHeading(90, 1000, {}, false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, EAST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, SOUTH), chassis.getPose().theta);
    
    chassis.moveToPoint(25, -48, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, false);
    pto.set_value(false);
    pros::delay(100);
    while (arm_sensor.get_position() < 11000) {intake.move(100);}
    while (arm_sensor.get_position() > 200) {intake.move(-127);}
    pto.set_value(true);
    pros::delay(100);
    intake.move(127);

    chassis.turnToHeading(90, 1000, {}, false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, EAST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, SOUTH), chassis.getPose().theta);
    
    // SE matchload
    matchload.set_value(true);
    chassis.turnToPoint(64, -47, 1000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(64, -47, 3000, {.forwards=true, .maxSpeed=55}, true);
    
    // SE long goal score
    chassis.turnToPoint(25, -47, 1000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(25, -47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, false);
    pto.set_value(false);
    pros::delay(100);
    while (arm_sensor.get_position() < 11000) {intake.move(100);}
    while (arm_sensor.get_position() > 200) {intake.move(-127);}
    pto.set_value(true);
    pros::delay(100);
    intake.move(127);

    chassis.turnToHeading(90, 1000, {}, false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, EAST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, SOUTH), chassis.getPose().theta);
    
    // NE matchload
    matchload.set_value(false);
    chassis.turnToHeading(0, 1000);
    left_mg.move(127);
    right_mg.move(127);
    pros::delay(500);
    // chassis.moveToPoint(36, -36, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.moveToPoint(36, 47, 3000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    
    chassis.turnToHeading(90, 1000, {}, false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, EAST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    matchload.set_value(true);
    chassis.moveToPoint(64, 47, 2000, {.forwards=true, .maxSpeed=55}, true);
    pros::delay(2000);
    
    // Nw long goal score
    chassis.turnToPoint(24, 64, 1000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(24, 64, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToPoint(-24, 64, 1000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    matchload.set_value(false);
    chassis.moveToPoint(-24, 64, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToPoint(-36, 50, 1000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(-36, 50, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    
    chassis.turnToHeading(270, 1000, {}, false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    
    chassis.moveToPoint(-25, 47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, false);
    pto.set_value(false);
    pros::delay(100);
    while (arm_sensor.get_position() < 11000) {intake.move(100);}
    while (arm_sensor.get_position() > 200) {intake.move(-127);}
    pto.set_value(true);
    pros::delay(100);
    intake.move(127);

    
    chassis.turnToHeading(270, 1000, {}, false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);

    // NW matchload
    matchload.set_value(true);
    chassis.turnToPoint(-64, 47, 1000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(-64, 47, 2000, {.forwards=true, .maxSpeed=55}, true);
    pros::delay(2000);
    
    // NW long goal score
    chassis.turnToPoint(-25, 47, 1000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(-25, 47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, false);
    pto.set_value(false);
    pros::delay(100);
    while (arm_sensor.get_position() < 11000) {intake.move(100);}
    while (arm_sensor.get_position() > 200) {intake.move(-127);}
    pto.set_value(true);
    pros::delay(100);
    intake.move(127);
    
    chassis.turnToHeading(270, 1000, {}, false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);

    // middle goal score
    chassis.turnToPoint(-47, 36, 1000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(-47, 36, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToPoint(-24, 24, 1000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(-24, 24, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToPoint(-10, 10, 1000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(-10, 10, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    
    // park in west parking
    chassis.turnToPoint(-60, 24, 1000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(-60, 24, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToHeading(210, 1000, {}, false);
    left_mg.move(80);
    right_mg.move(80);
    pros::delay(1000);
    left_mg.move(0);
    right_mg.move(0);

}