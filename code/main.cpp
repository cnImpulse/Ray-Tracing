#include "core/hittable.h"
#include "core/camera.h"
#include <iostream>

using std::cout;

int main(){
    // set scene
    camera camera(16.0 / 9.0);
    sphere sphere(point3(0, 0, -2), 0.5);

    // render
    camera.output_ppm_image(sphere, 400);

    return 0;
}