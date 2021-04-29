#ifndef RAYTRACING_H
#define RAYTRACING_H

#include <cmath>
#include <cstdlib>
#include <memory>
#include <iostream>
using std::shared_ptr;
using std::make_shared;
using std::ostream;
using std::cout;
using std::sqrt;

const double PI = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) { return degrees * PI / 180.0; }

inline double random_double() { return rand() / (RAND_MAX + 1.0); } // return a random double in [0, 1).
inline double random_double(double min, double max) { return min + (max-min)*random_double(); } // return in [min, max).

inline double clamp(double x, double min, double max) {
    if(x < min) return min;
    if(x > max) return max;
    return x;
}

#endif