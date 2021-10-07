#ifndef VECTO_H
#define VECTO_H
#include <iostream>
using namespace std;


class Vecto {
    private :
        int n;
        int *vt;
        static int count;
    public:
        Vecto(int size = 3);
        Vecto (const Vecto &k);
        ~Vecto();
        int &operator [] (int i) const;                             // do chỉ có 1 lớp nên dùng int 
        friend istream &operator >>( istream &in , Vecto &k);       // do có hai lớp nên phải dùng friend
        friend ostream &operator <<( ostream &out,const Vecto &k);
        const Vecto &operator = (const Vecto &k);
        Vecto operator + (const Vecto &k);
        Vecto operator - (const Vecto &k);
        int operator * (const Vecto &k);
        static int CountObject();
};

#endif
