#include "camera.h"

color ray_color(const hittable &scene, const ray& r, int depth = 20) {
    if(depth <= 0) return get_white();

    hit_record out_record;
    // random reflect until scene.hit() is false
    if(scene.hit(r, 0, INFINITY, out_record)) {
        point3 target = out_record.point + out_record.normal + random_in_unit_sphere();
        return 0.5 * ray_color(scene, ray(out_record.point, target - out_record.point), depth - 1);
    }

    vec3 dir = r.direction();
    double t = 0.5 * (dir.y + 1.0);
    return lerp(get_white(), get_blue(), t);
}

void camera::output_ppm_image(const hittable &scene , int scene_height) const {
    int width = scene_height * aspect_ratio, height = scene_height;
    double x = -width / 2.0, y = -height / 2.0, z = -x / tan(fovY / 2.0);
    point3 screen_origin(x, y, z);

    // output .ppm head
    cout << "P3\n" << width << ' ' << height << "\n255\n";

    // output pixels color
    for(int j = height-1; j >= 0; --j) {
        for(int i = 0; i < width; ++i) {
            point3 pixel = screen_origin + vec3(i, j, 0);
            sampling(scene, pixel, 10);
        }
    }
}

void camera::sampling(const hittable &scene, const point3 &pixel, int rand_sampling_frequency) const {
    color pixel_color(0, 0, 0);
    for(int k = 0; k < rand_sampling_frequency; ++k) {
        point3 temp = pixel + vec3(random_double(), random_double(), 0);
        ray r(position, temp - position);
        pixel_color += ray_color(scene, r);
    }
    write_color(cout, pixel_color / rand_sampling_frequency);
}