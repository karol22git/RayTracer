#pragma once
#include "Vector3.hpp"
class Ray {
    private:
        Point3 a;
        Vector3 b;
    public:
        Ray(const Vector3& origin, const Vector3& direction): a(origin), b(direction){}
        const Point3& origin() const {return a;}
        const Vector3& direction() const {return b;}
        Point3 at(double t) const { return a + t*b;}
};