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
Matrix::Matrix(int **data):n(sizeof(**data)/sizeof(int)){
    this->data = new int *[n];
    for (int i = 0 ; i < n ; i ++) {
        this->data[i] = new int [n];
    }
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++)
            this->data[i][j] = data[i][j];
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
double Matrix::operator()(const Matrix& M,int){
    double N[M.n][M.n];
    for (int p = 0 ; p < M.n ; p++)
        for (int q = 0 ; q < M.n ; q++)
            N[p][q] = M.data[p][q];
    int i , j , k ;
    double det = 1 , t;
    for ( i = 0 ; i < n - 1 ; i++){
        t = N[i+1][i] / N[i][i];
        for (j = i + 1 ; j < n ; j++){
            if (N[j][i] != 0){
                for (k = i ; k < n ; k++){
                    N[j][k] = N[j][k] * t - N[i][k];
                }
            }
        }
    }
    for (int o = 0 ; o < M.n ; o++) det *= N[o][o];
    return det;
}
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
    cout << endl;
    return out;
}