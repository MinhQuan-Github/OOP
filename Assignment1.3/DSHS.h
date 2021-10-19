#ifndef DSHS_H
#define DSHS_H
#include<iostream>
#include "Hocsinh.h"
// void swap(int &a1, int &a2);
// bool tang(Hocsinh l, Hocsinh r);
// bool giam(Hocsinh l, Hocsinh r);
class Node{
    public:
    Hocsinh data;
    Node *next;
};
class DSHS{
        Node *head;
        Node *tail;
    public:
        DSHS();
        DSHS(const DSHS &ds);
        ~DSHS() {
        }
        DSHS operator +(Hocsinh &);
        DSHS operator -(Hocsinh &);
        const DSHS &operator =(const DSHS &);
        Hocsinh operator ()(int &);
        friend ostream &operator << (ostream &,const DSHS &);
        // void Nhap();
        // void Xuat() const;
        // friend istream& operator >>(istream &in, DSHS &x);
        // friend ostream& operator <<(ostream &out,const DSHS &x);
        // void sapxep(bool (*compare)(Hocsinh,Hocsinh));
};
#endif