#pragma once
#include "Constants.hpp"
#include "Vector3.hpp"
#include "Sphere.hpp"
#include "Ray.hpp"
#include <vector>
#include "Color.hpp"
using namespace std;
class Camera {
    public:
        double aspect_ratio = 16.0/9.0;
        int image_width  = 400;
        int image_height;
        Point3 camera_center;
        Point3 pixel00_loc;    
        Vector3  pixel_delta_u;  
        Vector3  pixel_delta_v;
        int max_depth = 10;
        void Initialize() {
                image_height = int(image_width/aspect_ratio);
                image_height = (image_height < 1) ? 1: image_height;
                auto focal_length = 1.0;
                auto viewport_height = 2.0;
                auto viewport_width = viewport_height *(double(image_width/image_height));
                auto camera_center = Point3(0,0,0);
                auto viewport_u = Vector3(viewport_width,0,0);
                auto viewport_v = Vector3(0,-viewport_height,0);
                pixel_delta_u = viewport_u/image_width;
                pixel_delta_v = viewport_v/image_height;
                auto viewport_upper_left = camera_center - Vector3(0,0,focal_length) -
                viewport_u/2 - viewport_v/2;
                pixel00_loc = viewport_upper_left + 0.5*(pixel_delta_u +pixel_delta_v);
            }

            void render(struct hittable_list spheres){
                Initialize();
                std::cout<<"P3\n"<<image_width<<" "<<image_height<<"\n255\n";
                for(int j = 0 ; j<image_height ;++j) {
                    std::clog <<"\rScanlines remainings: "<<(image_height - j)<< " "<<std::flush;
                    for(int i = 0 ; i <image_width ; ++i) {
                        auto pixel_center = pixel00_loc + (i*pixel_delta_u) + (j*pixel_delta_v);
                        auto ray_direction = pixel_center - camera_center;
                        Ray r(camera_center,ray_direction);
                        auto pixel_color = ray_color_metal(r,spheres,max_depth);
                        write_color(std::cout,pixel_color);
                    }
            }
        
        std::clog<<"\rDone. \n";
    }
        
        Color ray_color(const Ray& r, struct hittable_list spheres) {
            struct hit_record rec;
            if(spheres.hit(r,0,infinity,rec)) return 0.5 * (rec.normal + sky_color);
            else {
                Vector3  unit_dir = unit_vector(r.direction());
                auto a = 0.5*(unit_dir.y() + 1.0);
                return (1.0-a)*sky_color + a*linear_blend_product;
            }
        }
         Color ray_color_metal(const Ray& r, struct hittable_list spheres, int depth) {
            if(depth <= 0) return color(0,0,0);
            struct hit_record rec;
            if(spheres.hit(r,0,infinity,rec)) {
                Vector3 direction = random_on_hemisphere(rec.normal);
                return 0.5 * ray_color_metal(Ray(rec.p, direction), spheres,depth-1);
            }
            else {
                Vector3  unit_dir = unit_vector(r.direction());
                auto a = 0.5*(unit_dir.y() + 1.0);
                return (1.0-a)*sky_color + a*linear_blend_product;
            }
        }
};