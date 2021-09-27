#include <iostream>
#include <iomanip>
#include "Mang.h"

using namespace std;

Mang::Mang(int n){
    data = new int [n];
    number = n;
    for (int i = 0 ; i < n ; i++) 
        this->data[i] = 0;
}

Mang::Mang(const Mang &k){
    data = new int [k.number];
    number = k.number;
    for (int i = 0 ; i < k.number ; i++) 
        this->data[i] = k.data[i];
}

Mang::~Mang(){
    delete [] data;
};

void Mang::setArr(int n) {
    data = new int [n];
    number = n;
}

void Mang::input(){
    cout <<"Nhập lần lượt các giá trị phần tử : ";
    for (int i = 0 ; i < number ; i++){
        cin >> this->data[i];
    }
    cout <<endl;
}

void Mang::output(){
    cout << " Giá trị các phần tử của mảng : ";
    for (int i = 0 ; i < number ; i++){
        cout << this->data[i] << " ";
    }
    cout << endl;
}

int Mang::getSize(){
    return (sizeof(this)/ sizeof(int));
}

void Mang::getValue(){
    cout <<"Nhập vị trí cần lấy giá trị trong mảng : ";
    int n ; cin >> n;
    cout <<"Gía trị của mảng tại vị trí " << n << " là " <<this->data[n-1]<<endl;
}

void Mang::updateValue(){
    cout <<"Nhập vị trí cần thay đổi giá trị trong mảng : ";
    int n ; cin >> n;
    cout <<"Nhập giá trị thay đổi tại vị trí đó : ";
    int temp ; cin >> temp;
    this->data[n-1] = temp;
}

void Mang::find(){
    cout <<"Nhập giá trị cần tìm trong mảng : ";
    int n ; cin >> n;
    bool test = false; int j = 0;
    int *b = new int [this->number];
    for (int i = 0 ; i < this->number ; i++){
        if (this->data[i] == n) {
            test = true;
            b[j++] = i;
        }
    }
    cout <<" => Vậy vị trí tìm được là : ";
    for (int k = 0 ; k < j ; k++){
        cout << b[k] + 1 << " ";
    }
    cout << endl;
}

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