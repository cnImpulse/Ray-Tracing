#include "image.h"

color ray_color(const sphere& sphere, const ray& r) {
    if(sphere.intersect(r)) return get_red();
    vec3 dir = r.direction();
    double t = 0.5 * (dir.y + 1.0);
    return lerp(get_white(), color(0.5, 0.5, 1.0), t);
}

void image::creat_image(const double aspect_ratio) {
    // set camera
    double viewport_height = 2.0;
    double viewport_width  = aspect_ratio * viewport_height;
    double focal_length    = 1.0;

    auto origin = point3(0, 0, 0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

    // set objects
    sphere sphere(point3(0, 0, -1), 0.5);

    // cout color
    for(int j=height-1; j>=0; --j) {
        for(int i=0; i<width; ++i){
            double u = double(i) / (width-1);
            double v = double(j) / (height-1);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            color pixel_color = ray_color(sphere, r);
            write_color(cout, pixel_color);
        }
    }
}