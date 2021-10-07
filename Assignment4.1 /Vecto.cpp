#include "Vecto.h"
#include <iostream>
using namespace std;

int Vecto::count = 0;

Vecto::Vecto(int size){
    this->n = size;
    vt = new int [n];
}

Vecto::Vecto(const Vecto &k){
    count++;
    this->n = k.n;
    for (int i = 0 ; i < n ; i++){
        this->vt[i] = k.vt[i];
    }
}

Vecto::~Vecto(){
    cout <<"Đang gọi hàm huỷ : ";
    delete [] vt;
}

istream &operator >>( istream &in , Vecto &k){
    // cout <<"Nhập số chiều của vecto : ";
    // cin >> k.n;
    cout <<"Nhập lần lượt các trọng số của vecto :";
    for (int i = 0 ; i < k.n ; i++){
        cin >> k.vt[i];
    }
    return in;
}

ostream &operator <<( ostream &out,const Vecto &k){
    cout <<"(";
    for (int i = 0 ; i < k.n ; i++){
        if (i == k.n - 1) cout << k.vt[i];
        else cout << k.vt[i] <<";";
    }
    cout <<")"<<endl;
    return out;
}

const Vecto &Vecto::operator = (const Vecto &k){
    if (this != &k) {
        n = k.n;
        delete [] vt;
        vt = new int [n];
        for (int i = 0 ; i < n ; i++){
            this ->vt[i] = k.vt[i];
        }
    }
    return *this;
}

int &Vecto::operator [] (int i) const{
    return vt[i];
}

Vecto Vecto::operator +(const Vecto &k){
    Vecto temp(n);
    for (int i = 0 ; i < n ; i ++){
        temp[i] = vt[i] + k[i];
    }
    return temp;
}

Vecto Vecto::operator -(const Vecto &k){
    Vecto temp(n);
    for (int i = 0 ; i < n ; i ++){
        temp[i] = vt[i] - k[i];
    }
    return temp;
}

int Vecto::operator * (const Vecto &k){
    int temp = 0;
    for (int i = 0 ; i < n ; i++){
        temp += this->vt[i] * k.vt[i];
    }
    return temp;
}

int Vecto::CountObject() {
    return count;
}
