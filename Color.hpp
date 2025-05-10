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


void write_color(std::ostream& out, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    out <<rbyte<<" "<<gbyte<<" "<<bbyte<<"\n";
}