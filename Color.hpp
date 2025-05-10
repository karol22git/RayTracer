#pragma once
#include "Vector3.hpp"
#include <iostream>
#include "Ray.hpp"
using color = Vector3;


/*
Pierwsza funkcja do manipulowania tworzonym
przez nas obrazem. W sposób liniowy, przechodzi przez
kolor A do koloru B i na podstawie tego procesu
tworzymy obraz..
*/
color ray_color(const Ray& r) {
    Vector3 unit_dir = unit_vector(r.direction());
    auto a = 0.5*(unit_dir.y() +1.0);
    return (1.0-a)*color(1.0,1.0,1.0) + a*color(1.0,0.0,0.0);
}

/*
Autorska funkcja do robienia tego co ray_color,
ale z wieksza kontrola uzytkownika. Mozemy obraz generwoac
od góry do dołu, albo od lewa do prawa. Samodzielnie wybieramy
takze kolor A i kolor B.

Warto zaznaczyc, ze jezeli chcemy stowrzyc obraz od prawa do lewa,
a nie od lewa do prawa, to powinniyms po prostu zmaienic stornami kolor
A i B, a nie dopisywac dodatkowego kodu


KOdy rgb są skalowane tak aby 1.0 to 255 a 0.0 to 0

kody rgb kolorow, np czerwony (1.0,0.0,0.0)
purpurowy (0.5,0.0,0.5)
niebieski (0.0,0.0,1.0)
zielony (0.0,1.0,0.0)
bialy (1.0,1.0,1.0)
czarny (0.0,0.0,0.0)
*/
color my_ray_color_manipulator(const Ray&r, color start, color end, char direction){
    double a;
    if (direction == 'y') {
        Vector3 unit_dir = unit_vector(r.direction());
        a = 0.5*(unit_dir.y() +1.0);
    }
    else {
        Vector3 unit_dir = unit_vector(r.direction());
        a = 0.5*(unit_dir.x() +1.0);
    }
    return (1.0-a)*end + a*start;
}

/*
Przestrzen R^3
C - punkt środka sfery, reprezentowany jako wektor od (0,0,0) do srodka sfery
r - jakis promien, wektor
ponizszy kod reprezentuje po prostu przeksztalcenie i rozwizanie
rownania sfery pod katem tego, czy dane promien przez nia przechodzi, czy nie.
Promien przechodzi przez sfery, wtedy i tylko wtedy gdy delta
rownania powstalego po podstawieniaach z rownania sfery jest wieksza badz rowna 0
*/
bool hit_sphere(const Point3& center, double radius, const Ray& r) {
    Vector3 oc = center - r.origin(); //
    auto a = dot(r.direction(), r.direction());
    auto b = -2.0 * dot(r.direction(), oc);
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    return (discriminant >= 0);
}

/*
kod tworzy na ekranie sfere o zadanym kolorze sphere_color,
w zadnamy srodku C i o zadanym promieniu radius
*/
color ray_color_with_sphere(const Ray& r, Point3 C, double radius,color sphere_color) {
    if (hit_sphere(C, radius, r)) return sphere_color;

    Vector3 unit_dir = unit_vector(r.direction());
    auto a = 0.5*(unit_dir.y() +1.0);
    return (1.0-a)*color(1.0,1.0,1.0) + a*color(1.0,0.0,0.0);
}



void write_color(std::ostream& out, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    out <<rbyte<<" "<<gbyte<<" "<<bbyte<<"\n";
}