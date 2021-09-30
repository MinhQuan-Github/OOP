#ifndef DSHS_H
#define DSHS_H
#include "Hocsinh.h"

void swap(int &num1, int &num2);
bool descending(Hocsinh l, Hocsinh r);
bool ascending(Hocsinh l, Hocsinh r);

class DSHS{
        const int n; // số học sinh trong danh sách
        Hocsinh *data; //mảng động chứa ds học sinh
    public:
        DSHS(int m = 3); //default constructor
        DSHS(const DSHS &ds);
        ~DSHS() {
            delete [] data;
        }
        void Nhap();
        void Xuat() const;
        friend istream &operator >>(istream &in, DSHS &a);           // Hàm nhap
        friend ostream &operator <<(ostream &out, const DSHS &a);    // Hàm xuất
        void sort(bool (*compare) (Hocsinh , Hocsinh));
};
#endif