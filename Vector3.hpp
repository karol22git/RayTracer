#pragma once
#include <cmath>
#include <iostream>

class Vector3 {
    public:
        Vector3(): e{0,0,0} {}
        Vector3(const double e0, const double e1, const double e2): e{e0,e1,e2} {}

        friend  std::ostream& operator <<(std::ostream& out, const Vector3 &v);
        friend  Vector3 operator+(Vector3 u, const Vector3 &v);
        friend  Vector3 operator-(Vector3 u, const Vector3 &v);
        friend  Vector3 operator*(Vector3 u, const Vector3 &v);
        friend  Vector3 operator*(double t, const Vector3 & v);
        friend  Vector3 operator*(Vector3 &v, double t);
        friend  Vector3 operator/(Vector3 v, double t);
        friend  double dot(const Vector3 &u, const Vector3 &v);
        friend  Vector3 cross(const Vector3 &u, const Vector3 &v);
        
        double x() const {return e[0];}
        double y() const {return e[1];}
        double z() const {return e[2];}
        
        Vector3 operator-() const {return Vector3(-e[0],-e[1],-e[2]);}
        double operator[](unsigned int i ) const {return e[i];}
        double& operator[](unsigned int i) {return e[i];}



        Vector3& operator+=(const Vector3& v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        Vector3& operator*=(const Vector3& v) {
            e[0] *= v.e[0];
            e[1] *= v.e[1];
            e[2] *= v.e[2];
            return *this;
        }

        Vector3& operator-=(const Vector3& v) {
            e[0] -= v.e[0];
            e[1] -= v.e[1];
            e[2] -= v.e[2];
            return *this;
        }
        
        Vector3& operator*=(double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        Vector3& operator/=(double t) {
            return *this *= 1/t;
        }

        double length() const {
            return std::sqrt(length_squared());
        }

        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

    private:
        double e[3]; 
};
using Point3 = Vector3;
