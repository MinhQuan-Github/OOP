#ifndef SETOFINTEGER_H
#define SETOFINTEGER_H
#include <iostream>
#include <iomanip>

using namespace std;

class SetOfInteger {
    private:
        int n;
        int *data;
        int top;
    public:
        SetOfInteger(int n = 0);
        SetOfInteger(int *data);
        SetOfInteger(const SetOfInteger &);
        ~SetOfInteger(){ delete [] data ; }
        SetOfInteger operator +(const SetOfInteger &);
        SetOfInteger operator -(const SetOfInteger &);
        SetOfInteger operator *(const SetOfInteger &);
        SetOfInteger operator +(int data);
        SetOfInteger operator -(int data);
        const SetOfInteger &operator =(const SetOfInteger &);
        int &operator [] (int i);
        bool operator () (int data);
        friend ostream &operator <<(ostream &out , const SetOfInteger &);
        bool isEmpty();
        bool isFull();
};


#endif