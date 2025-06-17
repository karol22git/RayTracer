#pragma once
#include "Ray.hpp"
#include <vector>
using namespace std;

struct hittable {
    virtual ~hittable() = default;
    virtual bool hit(const Ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};

struct hittable_list : public  hittable{
    vector<struct hittable*> list;
    hittable_list(){}
    hittable_list(struct hittable* s){
        add(s);
    }
    void add(struct hittable* s) {
        list.push_back(s);
    }

    bool hit(const Ray& r, double ray_tmin, double ray_tmax, hit_record &rec) const override {
        hit_record temp_rec;
        bool hit_anything = false;

        auto closest = ray_tmax;

        for(const auto& s: list) {
            if(s->hit(r,ray_tmin, closest, temp_rec)) {
                hit_anything = true;
                closest = temp_rec.t;
                rec = temp_rec;
            }
        }

        return hit_anything;
    }
};