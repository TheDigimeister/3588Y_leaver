#include "drive.hpp"
#include "main.h"
#include "pros/rtos.hpp"
#include "utils.hpp"

void testing(){

    // setup
    chassis.setPose(positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, WEST), positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, SOUTH), 180);
    level.set_value(true);
    pto.set_value(true);
    descore.set_value(true);
    gate.set_value(false);
    pros::delay(100);
    intake.move(127);

}