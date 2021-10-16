#include "Polynomial.h"
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

Polynomial::Polynomial(int level){
    this->level = level;
    this->data = new int [this->level + 1];
    for (int i = 0 ; i < this->level + 1 ; i++) this->data[i] = 0;
}
Polynomial::Polynomial(const Polynomial &P){
    this->level = P.level;
    this->data = new int [this->level + 1];
    for (int i = 0 ; i < this->level + 1 ; i++) this->data[i] = P.data[i];
}
Polynomial::Polynomial(int *data){
    this->level = sizeof(*data)/sizeof(int) - 1;
    this->data = new int [this->level + 1];
    for (int i = 0 ; i < this->level + 1; i++) this->data[i] = data[i];
}
Polynomial Polynomial::operator + (const Polynomial &P){
    int level; (this->level > P.level)? level = this->level : level = P.level;
    Polynomial temp(level);
    for (int i = 0 ; i < level + 1 ; i++) {
        if (i < this->level + 1 && i < P.level + 1) temp.data[i] = this->data[i] + P.data[i];
        if (i > this->level + 1) temp.data[i] = P.data[i];
        if (i > P.level + 1)     temp.data[i] = this->data[i];
    }
    
    return temp;
}
Polynomial Polynomial::operator - (const Polynomial &P){
    int level = (this->level > P.level)? this->level : P.level;
    Polynomial temp(level);
    for (int i = 0 ; i < level + 1 ; i++) {
        if (i < this->level + 1 && i < P.level + 1) temp.data[i] = this->data[i] - P.data[i];
        if (i > this->level + 1) temp.data[i] = -P.data[i];
        if (i > P.level + 1)     temp.data[i] = this->data[i];
    }
    return temp;
}
const Polynomial &Polynomial::operator = (const Polynomial &P){
    this->level = P.level;
    delete [] this->data;
    this->data = new int [P.level + 1];
    for (int i = 0 ; i < this->level + 1 ; i++) {
        this->data[i] = P.data[i];
    }
    return *this;
}
int &Polynomial::operator [] (int i) const {
    return this->data[i];
}
double Polynomial::operator () (int i) const{
    double value = data[0];
    for (int j = 0 ; j < this->level ; j ++) {
        value = value * i + data[j+1];
    }
    return value;
}
istream &operator >>(istream &in , Polynomial &P){
    cout << "Nhập lần lượt các hệ số của đa thức : ";
    for ( int i = 0 ; i < P.level + 1 ; i++) {
        cin >> P.data[i];
    }
    cout << endl;
    return in;
}
ostream &operator <<(ostream &out , const Polynomial &P){
    cout << "( " ;
    for ( int i = 0 ; i < P.level + 1 ; i++) {
        cout << P.data[i] << " ";
    }
    cout << ")"<< endl;
    return out;
}