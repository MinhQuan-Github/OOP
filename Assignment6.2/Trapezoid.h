#ifndef TRAPEZOID_H
#define TRAPEZOID_H
#include "Ground.h"
#include <iostream>
#include <string>

using namespace std;
class Trapezoid : public Ground {
    protected:
        float length;
        float width;
        float height;
    public:
        Trapezoid(string ID , double price , float length , float width , float height);
        double area();
        double totalPrice();
        void display();
};


#endif