#include <iostream>
#include "image.h"
using std::cout;

void image::creat_image() {
    for(int j=height-1; j>=0; --j) {
        for(int i=0; i<width; ++i){
            auto r = double(i) / (width-1);
            auto g = double(j) / (height-1);
            auto b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}