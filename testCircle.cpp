#include <iostream>
#include "Circle.h"
#include "Point2D.h"

int main(){
    Circle c1;
    Circle c2("green", Point2D(1,1), 2);
    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl; 
    std::cout << std::endl;

    c1.set_center(c2.get_center());
    c1.set_radius(c2.get_radius());
    c2.set_color("blue");

    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;
} 
