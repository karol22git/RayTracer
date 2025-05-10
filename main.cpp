#include <iostream>
#include "Color.hpp"
#include "Vector3.hpp"
#include "Ray.hpp"
int main() {
    auto aspect_ratio = 16.0/9.0;
    int image_width  = 400;
    int image_height = int(image_width/aspect_ratio);
    image_height = (image_height < 1) ? 1: image_height;

    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height *(double(image_width/image_height));
    auto camera_center = Point3(0,0,0);

    auto viewport_u = Vector3(viewport_width,0,0);
    auto viewport_v = Vector3(0,-viewport_height,0);

    auto pixel_delta_u = viewport_u/image_width;
    auto pixel_delta_v = viewport_v/image_height;

    auto viewport_upper_left = camera_center - Vector3(0,0,focal_length) -
    viewport_u/2 - viewport_v/2;

    auto pixel100_loc = viewport_upper_left + 0.5*(pixel_delta_u +pixel_delta_v);
    std::cout<<"P3\n"<<image_width<<" "<<image_height<<"\n255\n";
   // std::cout<<"pd1: "<<pixel_delta_u<<" pd2: "<<pixel_delta_v<<" pixel100: "<<pixel100_loc<<std::endl;
    for(int j = 0 ; j<image_height ;++j) {
        std::clog <<"\rScanlines remainings: "<<(image_height - j)<< " "<<std::flush;
        for(int i = 0 ; i <image_width ; ++i) {

           auto pixel_center = pixel100_loc + (i*pixel_delta_u) + (j*pixel_delta_v);
           auto ray_direction = pixel_center - camera_center;
           Ray r(camera_center,ray_direction);
          //color pixel_color = ray_color(r);
           color pixel_color = my_ray_color_manipulator(r,color(0.0,1.0,0.0),color(0.0,0.0,0.0),'y');
           write_color(std::cout,pixel_color);
        }
    }

    std::clog<<"\rDone. \n";
    return 0;
}