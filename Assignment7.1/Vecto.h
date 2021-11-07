#ifndef VECTO_H
#define VECTO_H
#include <iostream>
using namespace std;

template <typename T> 
class Vecto {
    private:
        int n; 
        T *data; 
    public:
        //Vecto();
        Vecto(int size = 3);
        Vecto(const Vecto<T> &x);
        ~Vecto(); 
        const Vecto &operator = (const Vecto<T> &x);
        Vecto operator + (const Vecto<T> &a);
        Vecto operator - (const Vecto<T> &a);
        T operator * (const Vecto<T> &a);
        T &operator [] (int i) const;
        template <typename U> friend istream &operator >>(istream &in, Vecto<U> &x);
        template <typename U> friend ostream &operator <<(ostream &out, const Vecto<U> &x);
};

#endif