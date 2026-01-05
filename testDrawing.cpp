#include <iostream>
#include "Drawing.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"

int main(){
    Drawing d;
    d.add_front(new Circle());
    d.add_front(new Square());
    d.add_back(new Rectangle());
    d.print_all();
    std::cout << std::endl;
    
    std::cout << "Area (all circles) = " << d.get_area_all_circles() << std::endl;
    std::cout << std::endl;

    std::cout << "Calling move_squares(10, 10)..." << std::endl;
    d.move_squares(10, 10);

    d.print_all();
}
