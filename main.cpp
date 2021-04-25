#include <iostream>
#include "image.h"
using std::cout;

int main(){
    image image(256, 256);

    cout << "P3\n" << image.get_width() << ' ' << image.get_height() << "\n255\n";

    image.creat_image();

    return 0;
}