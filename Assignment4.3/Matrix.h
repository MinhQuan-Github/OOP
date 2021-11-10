#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <iomanip>

using namespace std;

class Matrix {
    private:
        const int n;
        int **data;
    public:
        Matrix(int n = 0);
        Matrix(int **data);
        Matrix(const Matrix &);
        ~Matrix(){
            for (int i = 0 ; i < n ; i++){
                delete [] data[i];
            }
            delete [] data;
        }
        Matrix operator - (const Matrix &);
        Matrix operator * (const Matrix &);
        Matrix operator + (const Matrix &);
        const Matrix &operator = (const Matrix &);
        int operator () (int i, int j);
        operator int() ;
        //double operator()(const Matrix&, int);
        friend istream &operator >> (istream &in ,  Matrix &);
        friend ostream &operator << (ostream &out ,const Matrix &);
};

#endif