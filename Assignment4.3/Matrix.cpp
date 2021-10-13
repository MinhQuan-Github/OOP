#include "Matrix.h"
#include <iostream>
#include <iomanip>

using namespace std;

Matrix::Matrix(int n):n(n){
    this->data = new int *[n];
    for (int i = 0 ; i < n ; i++){
        this->data[i] = new int [n];
    }
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++)
            this->data[i][j] = 0;
}
Matrix::Matrix(const Matrix &k):n(k.n){
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++)
            this->data[i][j] = k.data[i][j];
}
Matrix Matrix::operator - (const Matrix &k){
    Matrix temp(this->n);
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++)
            temp.data[i][j] = this->data[i][j] - k.data[i][j];
    return temp;
}
Matrix Matrix::operator * (const Matrix &k){
    Matrix temp(this->n);
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            temp.data[i][j] = 0;
            for (int g = 0 ; g < n ; g++)
                temp.data[i][j] += this->data[i][g] * k.data[g][j];
        }
    }
    return temp;
}
Matrix Matrix::operator + (const Matrix &k){
    Matrix temp(this->n);
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++)
            temp.data[i][j] = this->data[i][j] + k.data[i][j];
    return temp;
}
const Matrix &Matrix::operator = (const Matrix &k){
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++)
            this->data[i][j] = k.data[i][j];
    return *this;
}
int Matrix::operator () (int i, int j){
    return this->data[i][j];
}
//int &operator (int *) ()
istream &operator >> (istream &in ,  Matrix &k){
    cout << "Nhập các hệ số : \n";
    for (int i = 0 ; i < k.n ; i++){
        cout << " - Nhập các hệ số hàng " << i << " : ";
        for (int j = 0 ; j < k.n ; j++){
            cin >> k.data[i][j];
        }
    }
    return in;      
}
ostream &operator << (ostream &out ,const Matrix &k){
    for (int i = 0 ; i < k.n ; i++){
        for (int j = 0 ; j < k.n ; j++){
            cout << setw(7) << k.data[i][j] ;
        }
        cout << endl;
    }
    return out;
}

