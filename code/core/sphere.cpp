#include "sphere.h"

bool sphere::hit(const ray &r, double t_min, double t_max, hit_record &out_record) const {
    vec3 oc = r.origin() - position;
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - radius*radius;
    auto discriminant = half_b * half_b - a * c;
    if(discriminant < 0) return false;

    auto sqrtd = sqrt(discriminant);
    auto t = (-half_b - sqrtd) / a;
    if(t < t_min || t > t_max) {
            t = (-half_b + sqrtd) / a;
            if(t < t_min || t > t_max) return false;
    }

    out_record.t      = t;
    out_record.point  = r.at(t);
    out_record.normal = (out_record.point - position) / radius;

    return true;
}