#ifndef RAYTRACING_H
#define RAYTRACING_H

#include <cmath>
#include <memory>
#include <iostream>
using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double PI = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) { return degrees * PI / 180.0; }

#include "vec3.h"
#include "ray.h"

#endif