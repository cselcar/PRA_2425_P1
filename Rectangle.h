#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape{
    private:
        static bool check(Point2D* vertices);
    
    protected:
        Point2D* vs;
    
    public:
        Rectangle();
        Rectangle(std::string color, Point2D* vertices);
        Rectangle(const Rectangle &r);
        ~Rectangle();
        Point2D get_vertex(int ind);
        virtual void set_vertices(Point2D *vertices);
        Point2D operator[](int ind);
        Rectangle& operator=(const Rectangle &r);
        friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);
        double area() const override;
        double perimeter() const override;
        void translate(double incX, double incY) override;
        void print() override;
};

static int const N_VERTICES = 4;

#endif
