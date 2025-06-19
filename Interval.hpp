#pragma once


class Interval {
    double min,max;
    public:
        Interval(double _min, double _max) {
            min  = _min;
            max = _max;
        }
    bool surrounds (double x) const {
        return (min<x)&&(x<max);
    }
    double clamp(double x) const {
        if (x<min) return min;
        if (x>max) return max;
        return x;
    }
};