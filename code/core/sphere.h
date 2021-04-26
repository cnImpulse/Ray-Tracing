#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"

class sphere : public hittable {
    public:
        point3 position = point3::zero();
        double radius = 1;

        sphere() {}
        sphere(const point3 &position, double radius): position(position), radius(radius) {}

        virtual bool hit(const ray &r, double t_min, double t_max, hit_record &out_record) const override;
};

#endif