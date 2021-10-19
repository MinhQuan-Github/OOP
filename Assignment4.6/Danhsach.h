#ifndef DANHSACH_H
#define DANHSACH_H
#include <string>
#include <iostream>
#include "Hocsinh.h"

using namespace std;

class Node{
    public:
        Hocsinh data;
        Node *next;
};

class Danhsach{
    private:
        Node *head;
        Node *tail;
    public:
        Danhsach();
        Danhsach(const Danhsach &);
        ~Danhsach();
        Danhsach operator +(Hocsinh &);
        Danhsach operator -(Hocsinh &);
        const Danhsach &operator =(const Danhsach &);
        Hocsinh operator () (int x);
        friend ostream &operator << (ostream &out , const Danhsach &);
};

#endif