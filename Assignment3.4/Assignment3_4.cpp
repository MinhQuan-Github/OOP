#include <iostream>
#include <iomanip>
#include "Mang.h"

using namespace std;

bool ascending(int l , int r){
    return l > r;
}

bool descending(int l , int r){
    return l < r;
}

void swap(int &num1 , int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void Mang::sort(bool(*compare)(int , int ) = ascending){
    for ( int i = 0 ; i < this->number - 1 ; i++){
        for ( int j = 0 ; j < this->number - i - 1; j++){
            if((*compare)(data[j],data[j+1]))
                swap(data[j],data[j+1]);
        }
    }
}

int main () {
    Mang A;
    A.setArr(5);
    A.input();
    A.output();
    //cout<<"kích thước mảng : " << A.getSize();
    A.getValue();
    A.updateValue();
    A.output();
    A.find();
    A.sort(ascending);
    A.output();
    A.sort(descending);
    A.output();
    return 0;
} 