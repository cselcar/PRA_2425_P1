#include "Square.h"

bool Square::check(Point2D* vertices){
    double d1, d2, d3, d4;
    
    d1 = vertices->distance(vertices[0], vertices[1]);
    d2 = vertices->distance(vertices[2], vertices[3]);
    d3 = vertices->distance(vertices[1], vertices[2]);
    d4 = vertices->distance(vertices[0], vertices[3]);

    if(d1 == d2 && d3 == d4 && d1 == d3){
        return true;
    }
    else{
        return false;
    }
}

Square::Square(){
    vs = new Point2D[4];
    color = "red";
    vs[0] = Point2D(-1,1);
    vs[1] = Point2D(1,1);
    vs[2] = Point2D(1,-1);
    vs[3] = Point2D(-1,-1);
}

Square::Square(std::string color, Point2D* vertices){
    this->color = color;
    vs = new Point2D[N_VERTICES];
    bool cuadrado = check(vertices);
    
    if(cuadrado == true){
        vs[0]= vertices[0];
        vs[1]= vertices[1];
        vs[2]= vertices[2];
        vs[3]= vertices[3];
    }
    else{
        throw std::invalid_argument("Estos vértices no forman un cuadrado");
    }
}

void Square::set_vertices(Point2D* vertices){
    bool correcto = check(vertices);
    if( correcto == false){
        throw std::invalid_argument("Estos vértices no forman un cuadrado");
    }
    else{
        for(int i = 0; i < N_VERTICES; i++){
            vs[i] = vertices[i];
        }
    }
}

std::ostream& operator<<(std::ostream &out, const Square &square){
    out<<"Color: "<<square.color<<std::endl<<"Vértices:"<<std::endl<<"v0 = "<<square.vs[0]<<std::endl<<"v1 = "<<square.vs[1]<<std::endl<<"v2 = "<<square.vs[2]<<std::endl<<"v3 = "<<square.vs[3];
    return out;
}

//metodos heredados de la clase Rectangle

void Square::print(){
    std::cout<<"Color: "<<color<<std::endl<<"Vértices:"<<std::endl<<"v0 = "<<vs[0]<<std::endl<<"v1 = "<<vs[1]<<std::endl<<"v2 = "<<vs[2]<<std::endl<<"v3 = "<<vs[3];
}
