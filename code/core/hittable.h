#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

struct hit_record {
    point3 point;
    vec3 normal;
    double t;
};

class hittable {
    public:
        virtual bool hit(const ray &r, double t_min, double t_max, hit_record &out_record) const = 0;
};

#endif