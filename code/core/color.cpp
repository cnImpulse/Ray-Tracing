#include "color.h"

void write_color(std::ostream &out, const color pixel_color) {
    out << static_cast<int>(255.999 * pixel_color.x) << ' '
        << static_cast<int>(255.999 * pixel_color.y) << ' '
        << static_cast<int>(255.999 * pixel_color.z) << '\n';
}

color get_red()     { return color(1, 0, 0); };
color get_green()   { return color(0, 1, 0); };
color get_blue()    { return color(0, 0, 1); };
color get_white()   { return color(1, 1, 1); };