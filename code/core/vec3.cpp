#include "vec3.h"

vec3 random_in_unit_sphere() {
    point3 res;
    do{
        res = vec3::random(-1, 1);
    }while(res.length_squared() >= 1);
    return res;
}

vec3 random_in_unit_sphere_surface() {
    return random_in_unit_sphere().normalize();
}

vec3 random_in_hemisphere(const vec3 &normal) {
    vec3 random_vec = random_in_unit_sphere();
    if(dot(random_vec, normal) > 0) return random_vec;
    return -random_vec;
}