#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <iomanip>

using namespace std;

class Polynomial {
    private:
        int level;
        int *data;
    public:
        Polynomial(int level = 3);          // Khởi tạo đối tượng Polynomial với độ dài bằng 3 và các phần tử bằng 0
        Polynomial(const Polynomial &);     // Khỏi tạo đối tượng Polynomial từ một đối tượng khác
        Polynomial(int *data);              // Khởi tạo đối tượng Polynomial từ một mảng
        ~Polynomial(){delete [] data;}      // Hàm huỷ , thu hồi bộ nhớ
        Polynomial operator + (const Polynomial &);
        Polynomial operator - (const Polynomial &);
        const Polynomial &operator = (const Polynomial &);
        int &operator [] (int i) const;
        double operator () (int i) const;
        friend istream &operator >>(istream &in , Polynomial &);
        friend ostream &operator <<(ostream &in , const Polynomial &);
};
#endif