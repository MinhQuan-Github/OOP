#ifndef HOCSINH_H
#define HOCSINH_H
#include <string>
using namespace std;
class Hocsinh{
        string ht;
        double toan, van, dtb;
        string xl;
        static int count;
    public:
        Hocsinh(string ten="", double t=0, double v=0);
        Hocsinh(const Hocsinh &x);
        void Nhap();
        void Xuat() const;
        const Hocsinh &operator =(const Hocsinh &);
        friend istream &operator >>(istream &in, Hocsinh &a); 
        friend ostream &operator <<(ostream &out, const Hocsinh &a);
        friend bool operator >(const Hocsinh & , const Hocsinh &);
        friend bool operator <(const Hocsinh & , const Hocsinh &);
        friend bool operator ==(const Hocsinh & , const Hocsinh &);
        friend bool operator >=(const Hocsinh & , const Hocsinh &);
        friend bool operator <=(const Hocsinh & , const Hocsinh &);
        friend bool operator !=(const Hocsinh & , const Hocsinh &);
        // friend Node *khoitaonode(Hocsinh &);
};
#endif