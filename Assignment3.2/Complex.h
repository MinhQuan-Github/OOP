#include <iostream>

using namespace std;

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
    private:
        float real , vir;
    public:
        Complex(float real = 0 , float vir = 0);            // hàm dựng 
        Complex(const Complex &);                           // Hàm dựng sao chép Complex khác
        ~Complex();                                         // Hàm huỷ 
        void setComplex(float a , float b);                 // Khởi tạo Complex
        void setComplex(float a);                           // Khởi tạo Complex từ số thực a
        friend istream &operator >>(istream &in ,Complex &);       // Hàm nhập
        friend ostream &operator <<(ostream &out ,const Complex &);// Hàm xuất
        float getReal(const Complex &);                     // Lấy phần thực
        float getVirt(const Complex &);                     // Lấy phần ảo
        void updateReal(Complex &);                         // Gán giá trị mới cho phần thực
        void updateVirt(Complex &);                         // Gán giá trị mới cho phần ảo
        float module();                                     // tính module số phức
        int compare(Complex &);                             // so sánh module số phức
        Complex operator +(const Complex &);                // Phép cộng số phức
        Complex operator -(const Complex &);                // Phép trừ số phức
        Complex operator *(const Complex &);                // Phép nhân số phức
        Complex operator /(const Complex &);                // Phép chia số phức
};

#endif
