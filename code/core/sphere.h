#ifndef SPHERE_H
#define SPHERE_H

#include "vec3.h"

class sphere
{
    public:
        point3 center = {0, 0, 0};
        double radius = 1;

        sphere(const point3& center, double radius): center(center), radius(radius) {}

        bool intersect(const ray& r) const {
                vec3 oc = r.origin() - center;
                auto a = dot(r.direction(), r.direction());
                auto b = 2.0 * dot(oc, r.direction());
                auto c = dot(oc, oc) - radius*radius;
                auto discriminant = b*b - 4*a*c;
                return (discriminant > 0);
        }
};

#endif