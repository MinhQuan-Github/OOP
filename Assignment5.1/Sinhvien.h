#ifndef SINHVIEN_H
#define SINHVIEN_H
#include "Ungcuvien.h"
#include <iostream>
#include <string>
using namespace std;

class Sinhvien : public Ungcuvien {
    private:
        string lop;
        float dtb;
    public:
        //Sinhvien();
        Sinhvien(string hoten = "" , string lop = "" , float dtb = 0);
        friend istream &operator >> (istream &in , Sinhvien &);
        friend ostream &operator << (ostream &out , const Sinhvien &);
        friend bool duocThuong(const Sinhvien &);
};

#endif