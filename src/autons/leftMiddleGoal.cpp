#include "main.h"
#include "utils.hpp"
#include "drive.hpp"

// scoring
// pto.set_value(false);
// pros::delay(100);
// while (arm_sensor.get_position() < 13000) {intake.move(127);}
// while (arm_sensor.get_position() > 200) {intake.move(-127);}
// pto.set_value(true);
// pros::delay(100);
// intake.move(127);

void leftMiddleGoal(){
    
    // setup
    chassis.setPose(positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, WEST), positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, NORTH), 0);
    level.set_value(true);
    pto.set_value(true);
    gate.set_value(false);
    descore.set_value(true);
    pros::delay(100);
    intake.move(127);
    matchload.set_value(true);

    // to matchload
    chassis.moveToPoint(-53, 44, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToHeading(270, 500, {}, false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);

    // matchload
    chassis.moveToPoint(-65, 46.5, 950, {.forwards=true, .maxSpeed=45, .minSpeed=45}, true);
    pros::delay(950);

    //high goal
    chassis.moveToPoint(-25.3, 47.8, 1250, {.forwards=false, .maxSpeed=60}, false);
    pto.set_value(false);
    gate.set_value(true);
    pros::delay(200);
    intake.move(127);
    pros::delay(50);
    intake.move(64);
    pros::delay(700);
    intake.move(-127);
    pros::delay(100);
    pto.set_value(true);
    pros::delay(100);
    intake.move(127);
    gate.set_value(false);
    matchload.set_value(false);

    // middle goal
    chassis.turnToPoint(-41, 47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.moveToPoint(-41, 47, 2000, {.forwards=true, .maxSpeed=100, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToPoint(-11.5, 18, 2000, {.forwards=true, .maxSpeed=100}, true);
    chassis.moveToPoint(-11.5, 18, 2000, {.forwards=true, .maxSpeed=90}, true);
    level.set_value(false);
    pros::delay(100);
    chassis.turnToHeading(320,2000, {.maxSpeed=80}, false);
    right_mg.move(-60);
    left_mg.move(-60);
    pros::delay(380);
    intake.move(0);
    right_mg.move(0);
    left_mg.move(0);
    pto.set_value(false);
    descore.set_value(false);
    gate.set_value(true);
    pros::delay(100);
    intake.move(45);
    pros::delay(650);
    intake.move(-127);
    pros::delay(200);
    pto.set_value(true);
    pros::delay(100);
    intake.move(127);
    gate.set_value(false);

    // descore
    chassis.turnToHeading(315, 1000, {}, false);
    left_mg.move(80);
    right_mg.move(80);
    pros::delay(500);
    chassis.turnToHeading(90, 1000, {}, false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    return;
    chassis.moveToPoint(-30, 31.5, 2000, {.forwards=true, .maxSpeed=127}, true);
    chassis.turnToHeading(90,1000, {}, true);
    chassis.moveToPoint(-5.7, 37, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToHeading(115, 2000, {}, false);

    // leftMiddleGoal

    // chassis.turnToPoint(-24, 24, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    // chassis.moveToPoint(-24, 24, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    // chassis.turnToHeading(315, 1000, {}, false);
    // level.set_value(false);
    // // chassis.moveToPoint(-10, 10, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    // left_mg.move(-50);
    // right_mg.move(-50);
    // pros::delay(550);
    // left_mg.move(0);
    // right_mg.move(0);
    // pto.set_value(false);
    // pros::delay(100);
    // while (arm_sensor.get_position() < 13000) {intake.move(127);}
    // while (arm_sensor.get_position() > 200) {intake.move(-127);}
    // pto.set_value(true);
    // level.set_value(true);
    // pros::delay(100);
    // intake.move(127);
    
    // chassis.turnToPoint(-48, 47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    // chassis.moveToPoint(-48, 47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    
    // chassis.turnToHeading(270, 1000, {}, false);
    // chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    
    // chassis.moveToPoint(-62, 47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    // chassis.turnToPoint(-27, 47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    // chassis.moveToPoint(-27, 47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, false);
    // pto.set_value(false);
    // pros::delay(100);
    // while (arm_sensor.get_position() < 13000) {intake.move(127);}
    // while (arm_sensor.get_position() > 200) {intake.move(-127);}
    // pto.set_value(true);
    // pros::delay(100);
    // intake.move(127);

    // chassis.turnToHeading(270, 500, {}, false);
    // chassis.setPose(chassis.getPose().x, positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);

    // left_mg.move(50);
    // right_mg.move(50);
    // pros::delay(150);
    // chassis.turnToHeading(340, 500, {.minSpeed=5, .earlyExitRange=1}, false);
    // left_mg.move(-50);
    // right_mg.move(-50);
    // pros::delay(300);
    // chassis.turnToHeading(270, 500, {.minSpeed=5, .earlyExitRange=1}, false);
    // left_mg.move(-100);
    // right_mg.move(-100);
    // pros::delay(450);
    // chassis.turnToHeading(270, 500, {}, false);

}