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
template <typename T>
Vecto<T>::Vecto(int size){
    this->n = size;
    this->data = new T [this->n];
} 

template <typename T>
Vecto<T>::Vecto(const Vecto<T> &x):n(x.n){
    this->data = new T [n];
    for(int i=0; i<n; i++)
        this->data[i] = x.data[i]; 
}
template <typename T>
Vecto<T>::~Vecto(){
    delete [] data; 
}
template <typename U>
istream &operator >>(istream &in, Vecto<U> &x){
    for(int i = 0; i<x.n; i++){
        cout<<"Toa do thu "<<i<< " : ";
        in>>x[i]; //
    }
    return in;
}
template <typename T>
T &Vecto<T>::operator [] (int i) const{
    return data[i];
}
template <typename U>
ostream &operator <<(ostream &out, const Vecto<U> &x){
    out <<"( ";
    for(int i=0;i < x.n;i++){
        out<<x[i]<<" ";
    }
    out<<" )"<<endl;
    return out;
}
template <typename T>
Vecto<T> Vecto<T>::operator + (const Vecto<T> &a)
{
    Vecto<T> b=*this;
    for(int i=0;i<b.n;i++)
    {
        b.data[i]+=a.data[i];
    }
    return b;
}
template <typename T>
Vecto<T> Vecto<T>::operator - (const Vecto<T> &a)
{
    Vecto<T> b = *this;
    for(int i=0;i<b.n;i++)
    {
        b.data[i]-=a.data[i];
    }
    return b;
}
template <typename T>
T Vecto<T>::operator * (const Vecto<T> &a)
{
    T p=0;
    for(int i=0;i<n;i++)
    {
        p+=this->data[i]*a.data[i];
    }
    return p;
}
template <typename T>
const Vecto<T> &Vecto<T>::operator = (const Vecto<T> &x){
    if (this != &x) {
        n = x.n;
        delete [] data;
        data = new T [n];
        for (int i = 0; i<n; i++)
            this->data[i] = x[i]; 
    }
    return *this;
}
#endif