#include "hittable.h"

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
    vec3 outward_normal = (out_record.point - position) / radius;
    out_record.set_face_normal(r, outward_normal);

    return true;
}

bool hittable_list::hit(const ray &r, double t_min, double t_max, hit_record &out_record) const {
    hit_record temp_rec;
    bool hit_anything = false;
    auto closest_so_far = t_max;

    for (const auto& object : objects) {
        if (object->hit(r, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            out_record = temp_rec;
        }
    }

    return hit_anything;
}