#include "Phanso.h"
#include <iostream>

using namespace std;

void Phanso::createFraction(int x , int y){
    this->a = x;
    this->b = y;
}

void Phanso::createFractionInt(int n){
    this->a = n;
    this->b = 1;
}

Phanso::Phanso(const Phanso &x){
    this->a = x.a;
    this->b = x.b;
}

Phanso::Phanso(int x){
    this->a = x;
}

Phanso::~Phanso(){
    //std::cout<<"Đã giải phóng vùng nhớ !!";
}

void Phanso::output(){
    cout << "- Phân số đó bằng : " << a << "/" <<b<<endl;
}

int Phanso::getNumerator(const Phanso &k){
    return k.a;
}

int Phanso::getDenominator(const Phanso &k){
    return k.b;
}

void Phanso::inverse(const Phanso &k){
    this->a = k.b;
    this->b = k.a;
}

int Phanso::UCLN(const Phanso &k){
    int temp;
    int x = k.a , y = k.b;
    while (y!=0){
        temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

void Phanso::compact(const Phanso &k){
    a = k.a / UCLN(k); 
    b = k.b / UCLN(k);
}

void Phanso::plusFraction(const Phanso &k , const Phanso &h){
    Phanso W,Q;
    W.a = k.b * h.a + k.a * h.b;
    W.b = k.b * h.b;
    Q.compact(W);
    cout <<Q.a << "/" <<Q.b << endl;
}

void Phanso::subtractFraction(const Phanso &k , const Phanso &h){
    Phanso W,Q;
    W.a = k.a * h.b - k.b * h.a;
    W.b = k.b * h.b;
    Q.compact(W);
    cout <<Q.a << "/" <<Q.b << endl;
}

void Phanso::multipleFraction(const Phanso &k , const Phanso &h){
    Phanso W,Q;
    W.a = k.a * h.a;
    W.b = k.b * h.b;
    Q.compact(W);
    cout <<Q.a << "/" <<Q.b << endl;
}

void Phanso::divideFraction(const Phanso &k , const Phanso &h){
    Phanso W,Q;
    W.a = k.a * h.b;
    W.b = k.b * h.a;
    Q.compact(W);
    cout <<Q.a << "/" <<Q.b << endl;
}

int Phanso::compare(const Phanso &k , const Phanso &h){
    if (k.a * 1.0 / k.b > h.a * 1.0 / h.b) return 1;
    if (k.a * 1.0 / k.b < h.a * 1.0 / h.b) return -1;
    return 0;
}
