#ifndef GIANGVIEN_H
#define GIANGVIEN_H
#include "Ungcuvien.h"
#include <iostream>
#include <string>
using namespace std;

class Giangvien : public Ungcuvien{
    private:
        string bomon;
        int sobaibao;
    public:
        Giangvien(string hoten = "" , string bomon = "" , int sobaibao = 0);
        friend istream &operator >> (istream &in , Giangvien &);
        friend ostream &operator << (ostream &out , const Giangvien &);
        friend bool duocThuong(const Giangvien &);
};

#endif