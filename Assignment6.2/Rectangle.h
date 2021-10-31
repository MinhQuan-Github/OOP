#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Ground.h"
#include <iostream>
#include <string>

using namespace std;
class Rectangle : public Ground {
    protected:
        float length;
        float width;
    public:
        Rectangle(string ID , double price , float length , float width);
        double area();
        double totalPrice();
        void display();
};


#endif