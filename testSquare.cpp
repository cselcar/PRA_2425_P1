#include <iostream>
#include "Square.h"
#include "Point2D.h"

int main(){
    Square r1;
    Point2D* vertices = new Point2D[4];
    vertices[0] = Point2D(-2,2);
    vertices[1] = Point2D(2,2);
    vertices[2] = Point2D(2,-2);
    vertices[3] = Point2D(-2,-2);
    Square r2("green", vertices);

    std::cout << "r1 = " << r1 << std::endl;
    std::cout << "r1.area() => " << r1.area() << "; r1.perimeter() => " << r1.perimeter() <<  std::endl;
    std::cout << std::endl;

    std::cout << "r2 = " << r2 << std::endl; 
    std::cout << "r2.area() => " << r2.area() << "; r2.perimeter() => " << r2.perimeter() <<  std::endl;
    std::cout << std::endl;

    vertices[1] = Point2D(1,0);
    try{
        r2.set_vertices(vertices);
    } catch(std::invalid_argument &e){
        std::cout << "r2.set_vertices(...) => std::invalid_argument: " << e.what() << std::endl; 
    }
}
