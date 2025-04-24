#include "Vector3.hpp"

std::ostream& operator<<(std::ostream& out, const Vector3 &v) {
    out<<v.e[0]<<" "<<v.e[1]<<" "<<v.e[2];
    return out;
}

Vector3 operator+(Vector3 u, const Vector3 &v) {
    u += v;
    return u;
}

Vector3 operator-(Vector3 u, const Vector3& v) {
    u -= v;
    return u;
}


Vector3 operator*(Vector3 u, const Vector3 &v) {
    u *=v;
    return u;
}

Vector3 operator*(double t, Vector3 & v) {
    v *= t;
    return v;
}
Vector3 operator*(Vector3 &v, double t) {
    v *= t;
    return v;
}

Vector3 operator/(Vector3 v, double t) {
    v /= t;
    return v;
}

double dot(const Vector3 &u, const Vector3 &v) {
    return u.e[0] * v.e[0] + u.e[1]*v.e[1] + u.e[2]* v.e[2];
}

Vector3 cross(const Vector3 &u, const Vector3 &v) {
    return Vector3(u.e[1]*v.e[2] - u.e[2]*v.e[1],
    v.e[2]*v.e[0] - u.e[0]*v.e[2],
    u.e[0]*v.e[1] - u.e[1]*v.e[0]);
}