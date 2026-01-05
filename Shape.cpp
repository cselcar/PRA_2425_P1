#include "Shape.h"

Shape::Shape(){
	color = "red";
}

Shape::Shape(std::string c){
	set_color(c);
}

std::string Shape::get_color() const{
	return color;
}

void Shape::set_color(std::string c){
	if(c == "red" || c == "green" || c == "blue"){
		color = c;
	}else{
		throw std::invalid_argument("Color no valido " + c);
	}
}
