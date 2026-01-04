#pragma once

#include "lemlib/chassis/chassis.hpp"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.hpp"
#include "pros/optical.hpp"
#include "pros/rotation.hpp"

extern pros::Controller controller;

extern lemlib::Chassis chassis;

extern pros::MotorGroup left_mg;
extern pros::MotorGroup right_mg;

extern pros::MotorGroup intake;

extern pros::ADIDigitalOut level;
extern pros::ADIDigitalOut matchload;
extern pros::ADIDigitalOut pto;
extern pros::ADIDigitalOut descore;
extern pros::ADIDigitalOut intake_lift;

extern pros::Distance front_dist;
extern pros::Distance back_dist;
extern pros::Distance left_dist;
extern pros::Distance right_dist;
extern pros::Distance front_disttwo;

extern pros::Rotation arm_sensor;

extern pros::Optical matchload_right;
extern pros::Optical matchload_left;

extern pros::ADIDigitalOut gate;