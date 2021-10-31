#include "Rectangle.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

Rectangle::Rectangle(string ID , double price , float length , float width):Ground(ID,price){
    this->length = length;
    this->width  = width;
}
double Rectangle::area(){
    return this->length * this->width;
}
double Rectangle::totalPrice(){
    return this->area() * this->price;
}
void Rectangle::display(){
    cout << "Rectangle information : " << endl;
    Ground::display();
    cout << "- Area                 : " << this->area() << endl;
    cout << "- Total price          : " << fixed << setprecision(0) << this->totalPrice() << endl;
}