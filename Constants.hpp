#pragma once
#include "Vector3.hpp"
#include "Ray.hpp"
#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

using color = Vector3;
using std::make_shared;
using std::shared_ptr;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

color sky_color = color(1.0,1.0,1.0);
color linear_blend_product  = color(0.5,0.7,1.0);

struct hit_record {
    Point3 p;
    Vector3 normal;
    double t;
    bool front_face;
    void set_face_normal(const Ray& r, const Vector3& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};