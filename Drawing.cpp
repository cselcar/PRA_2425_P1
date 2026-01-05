#include "Drawing.h"
#include "ListArray.h"
#include "Circle.h"
#include "Square.h"

Drawing::Drawing(){
    shapes = new ListArray<Shape*>();
}

Drawing::~Drawing(){
    for(int i = 0; i < shapes->size(); i++){
        delete shapes->get(i);
    }
    delete shapes;
}

void Drawing::add_front(Shape* shape){
    shapes->prepend(shape);
}

void Drawing::add_back(Shape* shape){
    shapes->append(shape);
}

void Drawing::print_all(){
    for(int i = 0; i < shapes->size(); i++){
        Shape* figura = shapes->get(i);
        figura->print();
    }
}

double Drawing::get_area_all_circles(){
    double area = 0;
    for(int i = 0; i < shapes->size(); i++){
        Shape* figura = shapes->get(i);
        Circle* circulo = dynamic_cast<Circle*>(figura);
        if(circulo){
            area = area + circulo->area();
        }
    }
    return area;
}

void Drawing::move_squares(double incX, double incY){
    for(int i = 0; i < shapes->size(); i++){
        Shape* figura = shapes->get(i);
        Square* cuadrado = dynamic_cast<Square*>(figura);
        if(cuadrado){
            cuadrado->translate(incX, incY);
        }
    }
}
