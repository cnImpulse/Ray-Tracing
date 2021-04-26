#ifndef SPHERE_H
#define SPHERE_H

#include "ray.h"
#include "vec3.h"

class sphere
{
    public:
        point3 position = {0, 0, 0};
        double radius = 1;

        sphere(const point3& position, double radius): position(position), radius(radius) {}

        double intersect(const ray& r) const {
                vec3 oc = r.origin() - position;
                auto a = dot(r.direction(), r.direction());
                auto b = 2.0 * dot(oc, r.direction());
                auto c = dot(oc, oc) - radius*radius;
                auto discriminant = b*b - 4*a*c;
                if(discriminant < 0) return -1.0;
                return (-b - sqrt(discriminant) ) / (2.0*a);
        }
};

#endif