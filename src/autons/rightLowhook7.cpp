#include "main.h"
#include "utils.hpp"
#include "drive.hpp"

void rightLowhook7()
{
    
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
    chassis.turnToPoint(-50, -47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.moveToPoint(-53, -46, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToHeading(270, 500, {}, false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);

    //matchload
    chassis.moveToPoint(-65, -47.5, 960, {.forwards=true, .maxSpeed=45, .minSpeed=45}, true);
    pros::delay(960);
    chassis.turnToPoint(-25, -47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    left_mg.move(-127);
    right_mg.move(-127);
    pros::delay(200);  
    left_mg.move(0);
    right_mg.move(0);
    matchload.set_value(false);
    pros::delay(100);


    //low goal
    // chassis.turnToPoint(-40.5, -47, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);

    chassis.turnToPoint(-24, -22, 2000, {.forwards=true, .maxSpeed=80, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.moveToPoint(-24, -22, 2000, {.forwards=true, .maxSpeed=90}, true);
    // chassis.moveToPoint(-19, -16, 2000, {.forwards=true, .maxSpeed=40}, false);
    // chassis.turnToPoint( 13.25, -13.25, 1000, {.forwards=true,.maxSpeed=80});
    chassis.moveToPoint(-11, -12, 2000, {.forwards=true, .maxSpeed=40}, false);
    pros::delay(100);
    intake.move(-50);    
    pros::delay(3000);
    intake.move(127);

    //descore
    chassis.turnToPoint(-39, -42, 2000, {.forwards=false, .maxSpeed=127,.minSpeed=5,.earlyExitRange=5}, true);
    chassis.moveToPoint(-39, -42, 2000, {.forwards=false, .maxSpeed=127}, true);
    chassis.turnToPoint(-6, -42, 2000, {.forwards=true, .maxSpeed=80}, false);
    left_mg.move(120);
    right_mg.move(120);
    pros::delay(425);
    descore.set_value(false);
    pros::delay(100);
    left_mg.move(-120);
    right_mg.move(-120);
    pros::delay(425);
    left_mg.move(0);
    right_mg.move(0);

}