#include "core/vec3.h"
#include "core/ray.h"
#include "core/color.h"
#include "core/image.h"
#include <iostream>

using std::cout;

int main(){
    const double aspect_ratio = 16.0 / 9.0;

    // set image
    const int image_width = 400, image_height = static_cast<int>(image_width / aspect_ratio);
    image image(image_width, image_height);

    // render
    cout << "P3\n" << image.get_width() << ' ' << image.get_height() << "\n255\n";
    image.creat_image(aspect_ratio);

    return 0;
}