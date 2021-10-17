#include "SetOfInteger.h"
#include <iostream>
#include <iomanip>

using namespace std;

SetOfInteger::SetOfInteger(int n){
    this->n = n;
    this->data = new int [n];
}
SetOfInteger::SetOfInteger(int *data){
    this->n = sizeof(*data)/sizeof(int);
    for ( int i = 0 ; i < n ; i++){
        this->data[i] = data[i];
    }
}
SetOfInteger::SetOfInteger(const SetOfInteger &S){
    this->n = S.n;
    for ( int i = 0 ; i < n ; i++){
        this->data[i] = S.data[i];
    }
}
SetOfInteger SetOfInteger::operator +(const SetOfInteger &S){
    int *tmp = new int [this->n + S.n]; int k = 0;
    for (int i = 0 ; i < this->n + S.n ; i++){
        tmp[i] = (i < this->n)? this->data[i] : S.data[i];
    }
    // for (int i = 0 ; i < this->n ; i++){
    //     for (int j = 0 ; j < S.n ; j++){
    //         if ( S.data[j] != this->data[i] ) {
    //             tmp[k] = S.data[j];
    //         }
    //     }
    // }
    SetOfInteger temp;

    return temp;
}
SetOfInteger SetOfInteger::operator -(const SetOfInteger &){

}
SetOfInteger SetOfInteger::operator *(const SetOfInteger &){

}
SetOfInteger SetOfInteger::operator +(int data){
    SetOfInteger temp(this->n + 1);
    for (int i = 0 ; i < this->n ; i++){
        temp.data[i] = this->data[i];
    }
    temp.data[this->n] = data;
    return temp;
}
SetOfInteger SetOfInteger::operator -(int data){
    int i; bool check = false;
    for (i = 0 ; i < this->n ; i++){
        if (this->data[i] == data) {
            check = true;
            break;
        }
    }
    SetOfInteger temp(this->n - 1);
    if (!check) return *this;
    else {
        for (int j = 0 ; j < this->n - 1 ; j++){
            if (j < i) temp.data[i] = this->data[i];
            else temp.data[j] = this->data[j+1];
        }
    }
    return temp;
}
const SetOfInteger &SetOfInteger::operator =(const SetOfInteger &S){
    this->n = S.n;
    delete [] this->data;
    this->data = new int [this->n];
    for ( int i = 0 ; i < n ; i++){
        this->data[i] = S.data[i];
    }
    return *this;
}
int &SetOfInteger::operator [] (int i){
    return this->data[i];
}
bool SetOfInteger::operator () (int data){
    for (int i = 0 ; i < this->n ; i++){
        if (this->data[i] == data) {
            return true;
        }
    }
    return false;
}
ostream &operator <<(ostream &out , const SetOfInteger &S){
    cout << "( ";
    for (int i = 0 ; i < S.n ; i++){
        cout << S.data[i] << " ";
    }
    cout << ")\n";
    return out;
}

// bool SetOfInteger::operator +(int data){
//     int number = sizeof(*this->data)/sizeof(int);
//     if (number == this->n) return false;
//     else this->data[number] = data;
//     return true;
// }
// bool SetOfInteger::operator -(int data){
//     int number = sizeof(*this->data)/sizeof(int);
//     if (number == 0) return false;
//     else {
//         int i;
//         for (i = 0 ; i < number ; i++){
//             if (this->data[i] == data) break;
//         }
//         for (int j = i ; j < number - 1 ; j++){
//             this->data[j] = this->data[j+1];
//         }
//         delete &this->data[number - 1];
//     }
//     return true;
// }