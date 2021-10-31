#include "Trapezoid.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

Trapezoid::Trapezoid(string ID , double price , float length , float width , float height):Ground(ID,price){
    this->length = length;
    this->width  = width;
    this->height = height;
}
double Trapezoid::area(){
    return (this->length + this->width) * this->height * (1.0 / 2);
}
double Trapezoid::totalPrice(){
    return this->area() * this->price * 0.9;
}
void Trapezoid::display(){
    cout << "Trapezoid information : " << endl;
    Ground::display();
    cout << "- Area                 : " << this->area() << endl;
    cout << "- Total price          : " << fixed << setprecision(0) << this->totalPrice() << endl;
}