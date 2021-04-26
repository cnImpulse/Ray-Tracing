#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>
using std::sqrt;
using std::ostream;

class vec3
{
    public:
        double x = 0;
        double y = 0;
        double z = 0;

        vec3() {}
        vec3(double x, double y, double z): x(x), y(y), z(z) {}

        double length_squared() const { return x*x + y*y + z*z; }
        double length() const { return sqrt(length_squared()); }

        vec3 operator-() const { return vec3(-x, -y, -z); }
        vec3 operator+(const vec3 &v) const { return vec3(x + v.x, y + v.y, z + v.z); }
        vec3 operator-(const vec3 &v) const { return *this + (-v); }
        vec3 operator*(double k) const { return vec3(k * x, k * y, k * z); }
        vec3 operator/(double k) const { return *this * (1 / k); }

        vec3 normalize() const { return *this / length(); }

        static vec3 zero()  { return vec3(0, 0, 0); }
        static vec3 up()    { return vec3(0, 1, 0); }
        static vec3 down()  { return vec3(0, -1, 0); }
        static vec3 right() { return vec3(1, 0, 0); }
        static vec3 left()  { return vec3(-1, 0, 0); }
        static vec3 front() { return vec3(0, 0, 1); }
        static vec3 back()  { return vec3(0, 0, -1); }
};

inline ostream& operator<<(ostream &out, const vec3 &v) {
    return out << v.x << ' ' << v.y << ' ' << v.z;
}

inline vec3 operator*(double k, const vec3& v){
    return v * k;
}

inline double dot(const vec3 &u, const vec3 &v) {
     return u.x * v.x + u.y * v.y + u.z * v.z; 
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.y * v.z - u.z * v.y,
                u.z * v.x - u.x * v.z,
                u.x * v.y - u.y * v.x);
}

inline vec3 lerp(const vec3 &start, const vec3 &end, double t) {
    return start + t * (end - start);
}

using point3 = vec3;
using color = vec3;

#endif