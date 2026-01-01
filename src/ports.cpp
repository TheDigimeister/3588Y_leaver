#include "main.h"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/motor_group.hpp"
#include "pros/rotation.hpp"

pros::MotorGroup intake({-1,3});

pros::Distance front_dist(19);
pros::Distance left_dist(2);
pros::Distance right_dist(10);
pros::Distance back_dist(9);
pros::Distance front_disttwo(18);

pros::ADIDigitalOut level('C');
pros::ADIDigitalOut pto('A');
pros::ADIDigitalOut matchload('E');
pros::ADIDigitalOut descore('H');
pros::ADIDigitalOut gate('G');

pros::Rotation arm_sensor(4);