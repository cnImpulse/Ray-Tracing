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
                auto a = r.direction.length_squared();
                auto half_b = dot(oc, r.direction());
                auto c = c.length_squared() - radius*radius;
                auto discriminant = half_b * half_b - a * c;
                if(discriminant < 0) return -1.0;
                return (-half_b - sqrt(discriminant) ) / a;
        }
};

#endif