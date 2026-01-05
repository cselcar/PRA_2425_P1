#include <iostream>
#include "Rectangle.h"
#include "Point2D.h"

int main(){
    Point2D* vertices = new Point2D[4];

    vertices[0] = Point2D(-1,0.5);
    vertices[1] = Point2D(1,0.5);
    vertices[2] = Point2D(1,-0.5);
    vertices[3] = Point2D(-1,-0.5);
    Rectangle r1("red",vertices);



    std::cout << "r1 = " << r1 << std::endl;
    std::cout << "r1.area() => " << r1.area() << "; r1.perimeter() => " << r1.perimeter() <<  std::endl;


    vertices[0] = Point2D(-1,1);
    vertices[1] = Point2D(1,1);
    vertices[2] = Point2D(1,-1);
    vertices[3] = Point2D(-1,-1);

    Rectangle r2("green", vertices);

    std::cout << "r1 = " << r1 << std::endl;
    std::cout << "r1.area() => " << r1.area() << "; r1.perimeter() => " << r1.perimeter() <<  std::endl;
    std::cout << "r2 = " << r2 << std::endl; 
    std::cout << "r2.area() => " << r2.area() << "; r2.perimeter() => " << r2.perimeter() <<  std::endl;
    std::cout << std::endl;

    std::cout << "r1.get_vertex(0) => " << r1.get_vertex(0) << "; r1[0] => " << r1[0] <<  std::endl;
    std::cout << "r1.get_vertex(3) => " << r1.get_vertex(3) << "; r1[3] => " << r1[3] <<  std::endl;
    std::cout << std::endl;

    r2.translate(10,10);
    std::cout << "r2.translate(10,10) =>" << std::endl << "    r2 = " << r2 << std::endl;
    std::cout << std::endl;

    vertices[1] = Point2D(1,0);
    try{
        r2.set_vertices(vertices);
    } catch(std::invalid_argument &e){
        std::cout << "r2.set_vertices(...) => std::invalid_argument: " << e.what() << std::endl; 
    }
    std::cout << std::endl;

    Rectangle r3 = r1;
    std::cout << "Rectangle r3 = r1; Aleshores..." << std::endl;
    std::cout << "r1 = " << r1 << std::endl;
    std::cout << "r3 = " << r3 << std::endl;
    r3.translate(100,100);
    std::cout << "r3.translate(100, 100); Aleshores..." << std::endl;
    std::cout << "r1 = " << r1 << std::endl;
    std::cout << "r3 = " << r3 << std::endl;

}
