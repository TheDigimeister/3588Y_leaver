#include "main.h"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.hpp"

pros::MotorGroup intake({-1,3});

pros::Distance front_dist(19);
pros::Distance left_dist(2);
pros::Distance right_dist(10);
pros::Distance back_dist(9);

pros::ADIDigitalOut level_left('C');
pros::ADIDigitalOut level_right('E');
pros::ADIDigitalOut pto('A');
// pros::ADIDigitalOut matchload('');
// pros::ADIDigitalOut descore_right('');
// pros::ADIDigitalOut descore_left('');