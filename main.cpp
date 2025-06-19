#include <iostream>
#include "Color.hpp"
#include "Vector3.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include <vector>
#include <memory>
#include "Camera.hpp"
using std::vector;

int main() {
    struct hittable_list spheres;
    spheres.add(new Sphere(Point3(0,0,-1),0.5,color(1.0,0.0,0.0)));
    spheres.add(new Sphere(Point3(0,-100.5,-1),100,color(0.0,1.0,0.0)));
    Camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width  = 400;

    cam.render(spheres);

}