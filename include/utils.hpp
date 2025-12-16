#pragma once
#include "pros/distance.hpp"

extern pros::Distance front_dist;
extern pros::Distance back_dist;
extern pros::Distance left_dist;
extern pros::Distance right_dist;


const float FRONT_DIST_OFFSET = 0.914;
const float BACK_DIST_OFFSET = 7.913;
const float LEFT_DIST_OFFSET = 5.124;
const float RIGHT_DIST_OFFSET = 5.111;
const float FRONTRIGHT_DIST_OFFSET = 0.0;
const float FRONTLEFT_DIST_OFFSET = 0.0;
const float BACKRIGHT_DIST_OFFSET = 0.0;
const float BACKLEFT_DIST_OFFSET = 0.0;

const float MM_TO_IN = 0.0393701;

enum WALL {
    NORTH,
    SOUTH,
    EAST,
    WEST,
    NE,
    SE,
    NW,
    SW,
};

extern float positionFromRaycast(float sensorReading, float sensorOffset, WALL wall);

extern float normalizeAngle(float angle);