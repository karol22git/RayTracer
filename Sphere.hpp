#pragma once
#include "Vector3.hpp"
#include "Ray.hpp"
#include "Constants.hpp"
#include <math.h>
using Color = Vector3;
double hit_sphere(const Point3& center, double radius, const Ray& r) {
    Vector3 oc = center - r.origin(); //
    auto a = dot(r.direction(), r.direction());
    auto b = -2.0 * dot(r.direction(), oc);
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    //musimy teraz znac gdzie sfera zostala uderzona.
    //obliczne to jest punkt uderzenia minus centrum sfery
    if (discriminant < 0) {
        return -1.0;
    } else {
        return (-b - std::sqrt(discriminant) ) / (2.0*a);
    }
}
class Sphere {
    public:
        Sphere(const Point3& center, const double _radius, const Color& _color): C(center), radius(_radius),color(_color){}
        bool hit(const Ray& r, double ray_tmin, double ray_tmax, hit_record& rec) {
            Vector3 oc = C - r.origin(); 
            auto a = dot(r.direction(), r.direction());
            auto b = -2.0 * dot(r.direction(), oc);
            auto c = dot(oc, oc) - radius*radius;
            auto discriminant = b*b - 4*a*c;
            if (discriminant < 0) {
                return false;
            }
            auto root = (-b - std::sqrt(discriminant) ) / (2.0*a);
           // auto root = (h - sqrtd) / a;
            if (root <= ray_tmin || ray_tmax <= root) {
                root = (-b + std::sqrt(discriminant) ) / (2.0*a);
                //root = (h + sqrtd) / a;
                if (root <= ray_tmin || ray_tmax <= root)
                    return false;
            }
            rec.t = root;
            rec.p = r.at(rec.t);
            rec.normal = (rec.p - C) / radius;
            rec.set_face_normal(r, rec.normal);
            return true;
        }
        color OuterNormal(const Ray& r) {
            auto t = hit_sphere(C, radius, r);
            if (t > 0.0) {
                Vector3 N = unit_vector(r.at(t) - C);
                return 0.5*Color(N.x()+1, N.y()+1, N.z()+1);
            }
            Vector3 unit_dir = unit_vector(r.direction());
            auto a = 0.5*(unit_dir.y() +1.0);
            return (1.0-a)*sky_color + a*linear_blend_product;
        }
    private:
        Point3 C;
        double radius;
        Color color;

};