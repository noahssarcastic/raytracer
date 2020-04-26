//
// Created by ninig on 4/11/2020.
//

#ifndef RAYTRACER_CONSTANTS_H
#define RAYTRACER_CONSTANTS_H

#include <cstdlib>
#include "RGBColor.h"


const RGBColor BLACK(0.0);
const RGBColor WHITE(1.0);
const RGBColor RED(1.0, 0.0, 0.0);

const double K_EPSILON = 0.0001;
const double K_HUGE_VALUE = 1.0E10;

const double 	PI 			= 3.1415926535897932384;
const double 	TWO_PI 		= 6.2831853071795864769;
const double 	INV_PI 		= 0.3183098861837906715;
const double 	INV_TWO_PI 	= 0.1591549430918953358;

const float 	INV_RAND_MAX = 1.0 / (float)RAND_MAX;

#endif //RAYTRACER_CONSTANTS_H
