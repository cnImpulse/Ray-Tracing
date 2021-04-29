#include "core/raytracing.h"
#include "core/hittable.h"
#include "core/camera.h"

#include <iostream>
using std::cout;

int main(){
    // set scene
    camera camera(16.0 / 9.0);
    hittable_list scene;
    scene.add(make_shared<sphere>(point3(0, 0, -2), 0.5));
    scene.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

    // render
    camera.output_ppm_image(scene, 400);

    return 0;
}