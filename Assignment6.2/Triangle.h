#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Ground.h"
#include <iostream>
#include <string>

using namespace std;
class Triangle : public Ground {
    protected:
        float bottom;
        float height;
    public:
        Triangle(string ID , double price , float bottom , float height);
        double area();
        double totalPrice();
        void display();
};


#endif