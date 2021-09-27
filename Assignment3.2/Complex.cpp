#include "Complex.h"
#include <iostream>
#include <math.h>

using namespace std;

Complex::Complex(float real  , float vir ){
    Complex::real = 0;
    Complex::vir = 0;
}

Complex::Complex(const Complex &k){
    this->real = k.real;
    this->vir  = k.vir ;
}

Complex::~Complex(){};

void Complex::setComplex(float a , float b){
    this->real = a;
    this->vir = b;
}

void Complex::setComplex(float a){
    this->real = a;
    this->vir = 0;
}

istream &operator >>(istream &in , Complex &k){
    cout << "Nhập lần lượt 2 phần tử thực và ảo : "; 
    cin >> k.real >> k.vir;
    return in;
}

ostream &operator <<(ostream &out , const Complex &k){
    cout << "(" << k.real << ";" << k.vir << ")";
    return out;
}

float Complex::getReal(const Complex &k){
    return k.real;
}                

float Complex::getVirt(const Complex &k){
    return k.vir;
}   

void Complex::updateReal(Complex &k){
    cout <<"Nhập giá trị cần gán cho phần thực : ";
    float temp; cin >> temp;
    k.real = temp;
}

void Complex::updateVirt(Complex &k){
    cout <<"Nhập giá trị cần gán cho phần ảo : ";
    float temp; cin >> temp;
    k.vir  = temp;
}

float Complex::module(){
    return sqrt(this->real * this->real + this->vir * this->vir);
}

int Complex::compare(Complex &k){
    Complex temp;
    temp.real = this->real;
    temp.vir  = this->vir ;
    if (temp.module() > k.module()) return 1;
    if (temp.module() < k.module()) return -1;
    return 0;
}

Complex Complex::operator +(const Complex &k){
    Complex temp;
    temp.real = this->real + k.real;
    temp.vir  = this->vir  + k.vir ;
    return temp;
}

Complex Complex::operator -(const Complex &k){
    Complex temp;
    temp.real = this->real - k.real;
    temp.vir  = this->vir  - k.vir ;
    return temp;
}

Complex Complex::operator *(const Complex &k){
    Complex temp;
    temp.real = this->real * k.real - this->vir * k.vir;
    temp.vir  = this->vir  * k.real + this->real * k.vir;
    return temp;
}

Complex Complex::operator /(const Complex &k){
    Complex temp;
    temp.real = (this->real * k.real + this->vir * k.vir)  / (k.real * k.real + k.vir * k.vir);
    temp.vir  = (k.real * this->vir - this->real * k.vir) / (k.real * k.real + k.vir * k.vir);
    return temp;
}