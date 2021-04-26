#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <iostream>

void write_color(std::ostream &out, const color pixel_color);

color get_red();
color get_green();
color get_blue();
color get_white();

#endif