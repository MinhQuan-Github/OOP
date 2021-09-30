#include "DSHS.h"
#include "Hocsinh.h"
#include <iostream>
#include <iomanip>
using namespace std;
DSHS::DSHS(int m):n(m){
    data = new Hocsinh [n];
}
DSHS::DSHS(const DSHS &ds):n(ds.n){
    data = new Hocsinh [n];
    for(int i = 0; i<n; i++){
        data[i] = ds.data[i];
    }
}
void DSHS::Nhap(){
    for(int i=0; i<n; i++){
        cout<<"Nhập hoc sinh thu "<<i<<":"<<endl;
        this->data[i].Nhap();
    }
}
void DSHS::Xuat() const{
    for(int i=0;i<n; i++) {
        cout<<setw(3)<<i+1;
        data[i].Xuat();
    }
}
istream &operator >>(istream &in, DSHS &a){
    for (int i = 0; i< a.n; i++){
        cout<<"Nhập hoc sinh thu "<<i<<":"<<endl;
        cin >> a.data[i];
    }
    return in;
}
ostream &operator <<(ostream &out, const DSHS &a){
    for(int i = 0 ; i < a.n ; i++) {
        cout << setw(3) << i + 1 ;
        cout << a.data[i];
    }
    return out;
}

bool ascending(Hocsinh l, Hocsinh r){
    return l > r;
}

bool descending(Hocsinh l, Hocsinh r){
    return l < r;
}

void swap(int &num1 , int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void DSHS::sort(bool (*compare) (Hocsinh , Hocsinh) = ascending){
    for (int i = 0 ; i < this->n ; i++){
        for (int j = i + 1 ; j < this->n ; j++){
            if ((*compare)(this->data[i] , this->data[j])) 
                swap(this->data[i] , this->data[j]);
        }
    }
}