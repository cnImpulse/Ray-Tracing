#ifndef CAMERA_H
#define CAMERA_H

#include "vec3.h"
#include "ray.h"
#include "color.h"
#include "sphere.h"
using std::cout;

class camera {
    private:
        point3 position = vec3::zero();
        double aspect_ratio = 1;
        double fovY = 30;
    public:
        camera() {}
        camera(double aspect_ratio): aspect_ratio(aspect_ratio) {}

        void output_ppm_image(const sphere &sphere, int scene_height) const;
};

#endif