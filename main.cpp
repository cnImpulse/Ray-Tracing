#include <iostream>
#include "vec3.h"
#include "image.h"
using std::cout;

int main(){
    image image(256, 256);

    cout << "P3\n" << image.get_width() << ' ' << image.get_height() << "\n255\n";

    image.creat_image();

    vec3 a(3, 2, 1), b(1,2,3);
    cout << a.normalize() << '\n' << b.normalize() << '\n';
    return 0;
}