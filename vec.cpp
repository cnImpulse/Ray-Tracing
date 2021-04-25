#include "vec3.h"

inline ostream& operator<<(ostream &out, const vec3 &v) {
    return out << v.x << ' ' << v.y << ' ' << v.z;
}

inline double dot(const vec3 &u, const vec3 &v) {
     return u.x * v.x + u.y * v.y + u.z * v.z; 
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.y * v.z - u.z * v.y,
                u.z * v.x - u.x * v.z,
                u.x * v.y - u.y * v.x);
}