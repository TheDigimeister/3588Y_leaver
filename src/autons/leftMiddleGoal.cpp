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
    chassis.setPose(positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, WEST), positionFromRaycast(fmax(front_dist.get(),front_disttwo.get())*MM_TO_IN, FRONT_DIST_OFFSET, NORTH), 0);
    level.set_value(true);
    pto.set_value(false);
    gate.set_value(false);
    descore.set_value(true);
    pros::delay(100);
    intake.move(127);
    matchload.set_value(true);

    // to matchload
    chassis.moveToPoint(-53, 44, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToHeading(270, 500, {}, false);
    chassis.setPose(positionFromRaycast(fmax(front_dist.get(),front_disttwo.get())*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);

    // matchload
    chassis.moveToPoint(-65, 46.5, 1000, {.forwards=true, .maxSpeed=45, .minSpeed=45}, true);
    pros::delay(1020);

    //high goal
    chassis.moveToPoint(-25.5, 47.8, 1250, {.forwards=false, .maxSpeed=60}, true);
    pros::delay(290);
    intake.move(0);
    matchload.set_value(false);
    pros::delay(960);
    pto.set_value(true);
    gate.set_value(true);
    pros::delay(100);
    intake.move(65);
    pros::delay(600);
    intake.move(-127);
    pros::delay(120);
    pto.set_value(false);
    pros::delay(100);
    intake.move(127);
    gate.set_value(false);

    // middle goal
    chassis.turnToPoint(-41, 47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.moveToPoint(-41, 47, 2000, {.forwards=true, .maxSpeed=100, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToPoint(-11.5, 18, 2000, {.forwards=true, .maxSpeed=100}, true);
    chassis.moveToPoint(-11.5, 18, 2000, {.forwards=true, .maxSpeed=90}, true);
    level.set_value(false);
    chassis.turnToHeading(317,2000, {.maxSpeed=80}, false);
    right_mg.move(-80);
    left_mg.move(-80);
    pros::delay(450);
    intake.move(0);
    right_mg.move(0);
    left_mg.move(0);
    pto.set_value(true);
    descore.set_value(false);
    gate.set_value(true);
    pros::delay(100);
    intake.move(45);
    pros::delay(650);
    intake.move(-127);
    pros::delay(200);
    pto.set_value(false);
    pros::delay(100);
    intake.move(127);

    // descore
    chassis.turnToHeading(315, 1000, {}, false);
    left_mg.move(80);
    right_mg.move(80);
    pros::delay(715);
    gate.set_value(false);
    chassis.turnToHeading(270, 1000, {}, false);
    chassis.setPose(positionFromRaycast(fmax(front_dist.get(),front_disttwo.get())*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    // left_mg.move(80);
    // right_mg.move(80);
    // pros::delay(1000);
    chassis.moveToPoint(-12, 38, 2000, {.forwards=false,.maxSpeed=127,.minSpeed=80});
    chassis.turnToHeading(308, 2000, {}, true);

}