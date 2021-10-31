#ifndef GROUND_H
#define GROUND_H
#include <iostream>
#include <string>

using namespace std;
class Ground {
    protected:
        string ID;
        long long price;
    public:
        Ground();
        Ground(string ID , double price);
        string getID();
        double getPrice();
        virtual double area();
        virtual double totalPrice();
        virtual void display() = 0;
};


#endif