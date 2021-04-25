#include "image.h"

void image::creat_image() {
    for(int j=height-1; j>=0; --j) {
        for(int i=0; i<width; ++i){
            color pixel_color(double(i) / (width-1), double(j) / (height-1), 0.25);
            write_color(cout, pixel_color);
        }
    }
}