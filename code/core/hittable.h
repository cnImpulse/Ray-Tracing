#ifndef HITTABLE_H
#define HITTABLE_H

#include "raytracing.h"
#include "vec3.h"
#include "ray.h"
#include <vector>
using std::vector;

struct hit_record {
    point3 point;
    vec3 normal;
    double t;
    bool front_face;

    // normal point against the incident ray
    void set_face_normal(const ray &r, const vec3 &outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable {
    public:
        virtual bool hit(const ray &r, double t_min, double t_max, hit_record &out_record) const = 0;
};

class hittable_list : public hittable {
    public:
        vector<shared_ptr<hittable>> objects;

        hittable_list() {}
        hittable_list(shared_ptr<hittable> object) { add(object); }

        void clear(){ objects.clear(); }
        void add(shared_ptr<hittable> object) { objects.push_back(object); }

        virtual bool hit(const ray &r, double t_min, double t_max, hit_record &out_record) const override;
};

class sphere : public hittable {
    public:
        point3 position = point3::zero();
        double radius = 1;

        sphere() {}
        sphere(const point3 &position, double radius): position(position), radius(radius) {}

        virtual bool hit(const ray &r, double t_min, double t_max, hit_record &out_record) const override;
};

#endif