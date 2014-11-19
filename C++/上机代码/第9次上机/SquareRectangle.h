#include<iostream>

class Square
{
protected:
    int edge;
public:
    virtual double GetArea();
    Square(int edg);
    ~Square(){};
};

Square::Square(int edg) {
    edge = edg;
}

double Square::GetArea() {
    return edge * edge;
}

double objGetArea(Square * base) {
    return base->GetArea();
}

class Rectangle:public Square
{
protected:
    int length;
public:
    double GetArea();
    Rectangle(int edg,int leng);
    ~Rectangle(){};
};

double Rectangle::GetArea() {
    return length * edge;
}

Rectangle::Rectangle(int edg, int leng) :Square(edg){
    length = leng;
}