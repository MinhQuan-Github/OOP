#include "Triangle.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

Triangle::Triangle(string ID , double price , float bottom , float height):Ground(ID,price){
    this->bottom = bottom;
    this->height = height;
}
double Triangle::area(){
    return this->bottom * this->height * (1.0 / 2);
}
double Triangle::totalPrice(){
    return this->area() * this->price * 0.9;
}
void Triangle::display(){
    cout << "Triangle information : " << endl;
    Ground::display();
    cout << "- Area                 : " << this->area() << endl;
    cout << "- Total price          : " << fixed << setprecision(0) << this->totalPrice() << endl;
}