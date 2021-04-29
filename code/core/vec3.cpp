#include "vec3.h"

point3 random_in_unit_sphere() {
    point3 res;
    do{
        res = vec3::random(-1, 1);
    }while(res.length_squared() >= 1);
    return res;
}