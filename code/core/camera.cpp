#include "camera.h"
#include "cmath"

color ray_color(const sphere& sphere, const ray& r) {
    if(sphere.intersect(r)) return get_red();
    vec3 dir = r.direction();
    double t = 0.5 * (dir.y + 1.0);
    return lerp(get_white(), get_blue(), t);
}

void camera::output_ppm_image(const sphere &sphere, int scene_height) const {
    int width = scene_height * aspect_ratio, height = scene_height;
    double x = -width / 2.0, y = -height / 2.0, z = -x / tan(fovY / 2.0);
    point3 screen_origin(x, y, z);

    // output .ppm head
    cout << "P3\n" << width << ' ' << height << "\n255\n";

    // output pixels color
    for(int j=height-1; j>=0; --j) {
        for(int i=0; i<width; ++i) {
            point3 offset(i, j, 0);
            point3 pixel = screen_origin + offset;
            ray r(position, pixel - position);
            write_color(cout, ray_color(sphere, r));
        }
    }
}