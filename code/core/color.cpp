#include "color.h"

void write_color(std::ostream &out, const color pixel_color) {
    // gamma correction
    auto r = sqrt(pixel_color.x);
    auto g = sqrt(pixel_color.y);
    auto b = sqrt(pixel_color.z);

    out << static_cast<int>(255.999 * clamp(r, 0, 1)) << ' '
        << static_cast<int>(255.999 * clamp(g, 0, 1)) << ' '
        << static_cast<int>(255.999 * clamp(b, 0, 1)) << '\n';
}

color get_red()     { return color(1, 0, 0); };
color get_green()   { return color(0, 1, 0); };
color get_blue()    { return color(0, 0, 1); };
color get_white()   { return color(1, 1, 1); };