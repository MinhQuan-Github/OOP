#include <iostream>
#include <iomanip>
#include "Mang.h"

using namespace std;

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