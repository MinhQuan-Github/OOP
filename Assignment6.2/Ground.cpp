#include "Ground.h"
#include <iostream>
#include <string>

using namespace std;
Ground::Ground(){}
Ground::Ground(string ID , double price):ID(ID),price(price){}
string Ground::getID(){
    return ID;
}
double Ground::getPrice(){
    return price;
}
double Ground::area(){
    return 0;
}
double Ground::totalPrice(){
    return 0;
}
void Ground::display(){
    cout << "ID                     : " << this->ID << endl;
    cout << "Price per square meter : " << this->price << endl;
}