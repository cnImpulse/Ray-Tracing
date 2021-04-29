#ifndef COLOR_H
#define COLOR_H

#include "raytracing.h"
#include "vec3.h"

void write_color(std::ostream &out, const color pixel_color);

color get_red();
color get_green();
color get_blue();
color get_white();

#endif