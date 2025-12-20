#include "drive.hpp"
#include "main.h"
#include "pros/rtos.hpp"
#include "utils.hpp"

void ezSkills(){

    // setup
    chassis.setPose(positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, WEST), positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, SOUTH), 180);
    level.set_value(true);
    pto.set_value(true);
    descore.set_value(true);
    gate.set_value(false);
    pros::delay(100);
    intake.move(127);

    // SW matchload
    matchload.set_value(true);
    chassis.moveToPoint(-50, -52, 2000, {.forwards=true, .maxSpeed=127}, true);

    chassis.turnToHeading(270, 1000, {}, false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);

    // pros::Task no_ball_leave([&] {
    //     int timeout = 0;
    //     int color_detect_time = 0;
    //     while (color_detect_time < 3 || timeout < 150) {
    //         if(fabs(normalizeAngle(matchload_right.get_hue()) - 220) > 15){color_detect_time++;}
    //         timeout++;
    //         pros::delay(20);
    //     }
    //     color_detect_time = 0;
    //     while (color_detect_time < 3 || timeout < 150) {
    //         if(fabs(normalizeAngle(matchload_right.get_hue()) - 220) < 15){color_detect_time++;}
    //         timeout++;
    //         pros::delay(20);
    //     }
    //     chassis.cancelMotion();
    //     std::printf(timeout);

    // });

    // pros::Task no_ball_leave([&] {
    //     int timeout = 0;
    //     int detection_count = 0;
    //     while(matchload_right.get_proximity() < )
    // })

    chassis.moveToPoint(-67, -48.25, 2000, {.forwards=true, .maxSpeed=55}, true);
    pros::delay(2800);
    // left_mg.move(-50);
    // right_mg.move(-50);
    // pros::delay(200);
    // left_mg.move(60);
    // right_mg.move(60);
    // pros::delay(900);
    
    // SE long goal score
    chassis.turnToPoint(-30, -64, 1000, {.forwards=false, .maxSpeed=80, .minSpeed=5, .earlyExitRange=1}, true);
    intake.move(0);
    chassis.moveToPoint(-30, -64, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=127, .earlyExitRange=5}, true);
    // chassis.turnToPoint(30, -64, 1000, {.forwards=false, .maxSpeed=80, .minSpeed=5, .earlyExitRange=1}, true);
    matchload.set_value(false);
    chassis.moveToPoint(30, -64, 3000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToPoint(38, -47, 1000, {.forwards=false, .maxSpeed=80, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(38, -47, 2000, {.forwards=false, .maxSpeed=127}, true);
    
    chassis.turnToHeading(90, 1000, {}, false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, EAST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, SOUTH), chassis.getPose().theta);
    intake.move(127);
    chassis.moveToPoint(25, -48, 1000, {.forwards=false, .maxSpeed=127}, false);
    pto.set_value(false);
    gate.set_value(true);
    pros::delay(200);
    intake.move(120);
    pros::delay(80);
    intake.move(51);
    pros::delay(800);
    intake.move(-127);
    pros::delay(200);
    // intake.move(127);
    // pros::delay(100);
    // intake.move(60);
    // pros::delay(300);
    // intake.move(-127);
    // pros::delay(200);   
    pto.set_value(true);
    pros::delay(100);
    intake.move(127);
    gate.set_value(false);

    chassis.turnToHeading(90, 1000, {}, false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, EAST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, SOUTH), chassis.getPose().theta);
    
    // SE matchload
    matchload.set_value(true);
    chassis.turnToPoint(65, -48, 1000, {.forwards=true, .maxSpeed=80, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(65, -48, 3000, {.forwards=true, .maxSpeed=55}, true);
    pros::delay(2800);
    // left_mg.move(-50);
    // right_mg.move(-50);
    // pros::delay(200);
    // left_mg.move(60);
    // right_mg.move(60);
    // pros::delay(900);

    
    // SE long goal score again
    chassis.turnToPoint(25, -49, 1000, {.forwards=false, .maxSpeed=80, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(25, -49, 2500, {.forwards=false, .maxSpeed=55}, false);
    pto.set_value(false);
    gate.set_value(true);
    pros::delay(200);
    intake.move(100);
    pros::delay(80);
    intake.move(35);
    pros::delay(800);
    // intake.move(-127);
    // pros::delay(200);
    // intake.move(127);
    // pros::delay(100);
    // intake.move(60);
    // pros::delay(300);
    intake.move(-127);
    pros::delay(200);    
    pto.set_value(true);
    pros::delay(100);
    intake.move(127);
    gate.set_value(false);

    chassis.turnToHeading(90, 1000, {}, false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, EAST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, SOUTH), chassis.getPose().theta);
    
    // NE long goal score
    matchload.set_value(false);

    chassis.moveToPose(64, -16, 0, 2000, {.horizontalDrift=15, .minSpeed=127});
    // left_mg.move(50);
    // right_mg.move(50);
    pros::delay(200);
    pto.set_value(false);
    gate.set_value(true);
    pros::delay(200);
    intake.move(100);
    pros::delay(200);
    intake.move(-127);
    pros::delay(300);
    pto.set_value(true);
    pros::delay(100);
    intake.move(127);
    gate.set_value(false);
    // pros::delay(500);

    chassis.turnToHeading(0, 1000, {},false);
    left_mg.move(80);
    right_mg.move(80);
    pros::delay(2000);

    chassis.turnToHeading(270, 1000, {}, false);
    chassis.setPose(positionFromRaycast(back_dist.get()*MM_TO_IN, BACK_DIST_OFFSET, EAST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);

    gate.set_value(false);
    matchload.set_value(true);
    // chassis.moveToPoint(36, -36, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.moveToPoint(50, 45, 2000, {.forwards=true, .maxSpeed=80, .minSpeed=80}, false);
    chassis.turnToHeading(90, 1000, {.maxSpeed=80}, false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, EAST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    
    chassis.moveToPoint(25, 47, 1200, {.forwards=false, .maxSpeed=55}, false);
    pto.set_value(false);
    gate.set_value(true);
    pros::delay(200);
    intake.move(100);
    pros::delay(80);
    intake.move(50);
    pros::delay(800);
    intake.move(-127);
    pros::delay(200);
    pto.set_value(true);
    pros::delay(100);
    intake.move(127);
    // matchload.set_value(false);
    gate.set_value(false);


    // NE matchload
    chassis.moveToPoint(65, 48.5, 2000, {.forwards=true, .maxSpeed=55}, true);
    pros::delay(2800);
    chassis.moveToPoint(25, 48, 2000, {.forwards=false, .maxSpeed=55}, false);
    pto.set_value(false);
    gate.set_value(true);
    pros::delay(200);
    intake.move(100);
    pros::delay(80);
    intake.move(40);
    pros::delay(800);
    intake.move(-127);
    pros::delay(200);
    pto.set_value(true);
    pros::delay(100);
    intake.move(127);
    // matchload.set_value(false);
    gate.set_value(false);
    // left_mg.move(-50);
    // right_mg.move(-50);
    // pros::delay(200);
    // left_mg.move(60);
    // right_mg.move(60);
    // pros::delay(900);

    // NW matchload
    chassis.moveToPoint(50, 48, 2000, {.forwards=true, .maxSpeed=80}, false);
    chassis.turnToPoint(30, 64, 1000, {.forwards=false, .maxSpeed=80, .minSpeed=80, .earlyExitRange=3}, true);
    chassis.moveToPoint(30, 64, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=127, .earlyExitRange=5}, true);
    // chassis.turnToPoint(-30, 64, 1000, {.forwards=false, .maxSpeed=80, .minSpeed=5, .earlyExitRange=1}, true);
    matchload.set_value(false);
    chassis.moveToPoint(-30, 64, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToPoint(-36, 50, 1000, {.forwards=false, .maxSpeed=80, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(-39, 46, 2500, {.forwards=false, .maxSpeed=127}, true);
    
    chassis.turnToHeading(270, 1000, {}, false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    
    // chassis.moveToPoint(-25, 48, 1000, {.forwards=false, .maxSpeed=55}, false);
    // pto.set_value(false);
    // gate.set_value(true);
    // pros::delay(200);
    // intake.move(127);
    // pros::delay(80);
    // intake.move(40);
    // pros::delay(800);
    // intake.move(-127);
    // pros::delay(200);
    // // intake.move(127);
    // // pros::delay(100);
    // // intake.move(60);
    // // pros::delay(300);
    // // intake.move(-127);
    // // pros::delay(200);    
    // pto.set_value(true);
    // pros::delay(100);
    // intake.move(127);
    // gate.set_value(false);

    
    // chassis.turnToHeading(270, 1000, {}, false);
    // chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);

    // NW matchload
    matchload.set_value(true);
    chassis.turnToPoint(-65, 47, 1000, {.forwards=true, .maxSpeed=80, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPoint(-65, 47, 3000, {.forwards=true, .maxSpeed=55}, true);
    pros::delay(2800);
    // left_mg.move(-50);
    // right_mg.move(-50);
    // pros::delay(200);
    // left_mg.move(60);
    // right_mg.move(60);
    // pros::delay(900);
    
    // // NW long goal score again
    // chassis.turnToPoint(-25, 48, 1000, {.forwards=false, .maxSpeed=80, .minSpeed=5, .earlyExitRange=1}, true);
    // chassis.moveToPoint(-25, 48, 2500, {.forwards=false, .maxSpeed=60}, false);
    // pto.set_value(false);
    // gate.set_value(true);
    // pros::delay(200);
    // intake.move(127);
    // pros::delay(80);
    // intake.move(40);
    // pros::delay(800);
    // intake.move(-127);
    // pros::delay(200);
    // // intake.move(127);
    // // pros::delay(100);
    // // intake.move(60);
    // // pros::delay(300);
    // // intake.move(-127);
    // // pros::delay(200);    
    // pto.set_value(true);
    // pros::delay(100);
    // intake.move(127);
    // matchload.set_value(false);
    // gate.set_value(false);
    
    // chassis.turnToHeading(270, 1000, {}, false);
    // chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);

    // middle goal score
    // chassis.turnToPoint(-47, 36, 1000, {.forwards=true, .maxSpeed=80, .minSpeed=5, .earlyExitRange=1}, true);
    // chassis.moveToPoint(-47, 36, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToHeading(270, 1000, {}, false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    chassis.turnToPoint(-24, 24, 1000, {.forwards=false, .maxSpeed=80}, true);
    chassis.moveToPoint(-24, 24, 2000, {.forwards=false, .maxSpeed=80}, true);
    pros::delay(800);
    matchload.set_value(true);
    chassis.turnToHeading(315, 1000, {.maxSpeed=80}, false);
    // chassis.turnToPoint(-10, 10, 1000, {.forwards=false, .maxSpeed=80}, true);
    level.set_value(false);
    left_mg.move(-60);
    right_mg.move(-60);
    pros::delay(700);
    left_mg.move(0);
    right_mg.move(0);
    // chassis.moveToPoint(-10, 10, 2000, {.forwards=false, .maxSpeed=60}, false);
    pto.set_value(false);
    gate.set_value(true);
    pros::delay(200);
    intake.move(45);
    pros::delay(200);
    intake.move(20);
    pros::delay(1000);
    intake.move(-127);
    pros::delay(200);
    // intake.move(127);
    // pros::delay(50);
    // intake.move(30);
    // pros::delay(400);
    // intake.move(-127);
    // pros::delay(200);    
    pto.set_value(true);
    pros::delay(100);
    intake.move(-127);
    matchload.set_value(false);
    gate.set_value(false);
    
    // park in west parking
    left_mg.move(50);
    right_mg.move(50);
    pros::delay(100);
    // chassis.turnToPoint(-62, 18, 1000, {.forwards=true, .maxSpeed=80, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.moveToPose(-62, 18, 180, 2000, {.forwards=true, .horizontalDrift=13, .minSpeed=80}, true);
    chassis.turnToHeading(180, 1000, {}, false);
    left_mg.move(70);
    right_mg.move(70);
    pros::delay(1550);
    left_mg.move(0);
    right_mg.move(0);

    // pto.set_value(false);
    // gate.set_value(true);
    // pros::delay(200);
    // intake.move(127);
    // pros::delay(200);
    // // intake.move(60);
    // // pros::delay(800);
    // intake.move(-127);
    // pros::delay(200);
    // // intake.move(127);
    // // pros::delay(50);
    // // intake.move(30);
    // // pros::delay(400);
    // // intake.move(-127);
    // // pros::delay(200);    
    // pto.set_value(true);
    // pros::delay(100);
    // intake.move(127);
    // matchload.set_value(false);
    // gate.set_value(false);

}