#pragma once
#include "Vector3.hpp"
#include "Interval.hpp"
#include <iostream>
#include "Ray.hpp"
using color = Vector3;

void write_color(std::ostream& out, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    static const Interval intensity(0.000, 0.999);
    int rbyte = int(256 * intensity.clamp(r));
    int gbyte = int(256 * intensity.clamp(g));
    int bbyte = int(256 * intensity.clamp(b));

    out <<rbyte<<" "<<gbyte<<" "<<bbyte<<"\n";
}