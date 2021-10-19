#include "DSHS.h"
#include "Hocsinh.h"
#include <iostream>
#include <iomanip>
using namespace std;
DSHS::DSHS(){
    head=NULL;
    tail=NULL;
}
DSHS::DSHS(const DSHS &ds){
    // data = new Hocsinh [n];
    // for(int i = 0; i<n; i++){
    //     data[i] = ds.data[i];
    // }
    head=ds.head;
    tail=ds.tail;
}
Node *khoitaonode(Hocsinh &hs){
    Node *p=new Node;
    p->data=hs;
    p->next=NULL;
    return p;
}
DSHS DSHS::operator +(Hocsinh &hs){
    Node *p=khoitaonode(hs);
    if(head==NULL) head=tail=p;
    else{
        tail->next=p;
        tail=p;
    }
    return *this;
}
DSHS DSHS::operator -(Hocsinh &hs){
    Node *p=head;
    if(head->data==hs) {head=head->next; return *this;}
    while(p!=NULL){
        if(p->next->data==hs) {
            p->next=p->next->next;
            return *this;
        }
    }
    return *this;
}
const DSHS &DSHS::operator =(const DSHS &ds){
    head=ds.head;
    tail=ds.tail;
    return *this;
}
Hocsinh DSHS::operator ()(int &x){
    Hocsinh a;
    int temp=0;
    Node *k=head;
    while(k!=NULL){
        temp++;
        if(temp==x) return k->data;
    }
    return a;
}
ostream &operator<<(ostream &out, const DSHS &ds){
    Node *k=ds.head;
    int a=1;
    while(k!=NULL){
        cout<<"hoc sinh thu "<<a++<<": "<<endl;
        cout<<k->data<<endl;
        k=k->next;
    }
    return out;
}
// void DSHS::Nhap(){
//     for(int i=0; i<n; i++){
//         cout<<"Nhap hoc sinh thu "<<i<<":"<<endl;
//         this->data[i].Nhap();
//     }
// }
// void DSHS::Xuat() const{
//     for(int i=0;i<n; i++) {
//         cout<<setw(3)<<i+1;
//         data[i].Xuat();
//     }
// }
// istream &operator >>(istream &in, DSHS &a){
//     for (int i = 0; i< a.n; i++){
//         cout<<"Nhap hoc sinh thu "<<i<<":"<<endl;
//         cin >> a.data[i];
//     }
//     return in;
// }
// ostream &operator <<(ostream &out, const DSHS &a){
//     for(int i = 0 ; i < a.n ; i++) {
//         cout << setw(3) << i + 1 ;
//         cout << a.data[i];
//     }
//     return out;
// }
// bool tang(Hocsinh l , Hocsinh r){
//     return l > r;
// }

// bool giam(Hocsinh l , Hocsinh r){
//     return l < r;
// }
// void swap(int &a1 , int &a2){
//     int temp = a1;
//     a1 = a2;
//     a2 = temp;
// }
// void DSHS::sapxep(bool(*compare)(Hocsinh ,Hocsinh ) = tang){
//     for ( int i = 0 ; i < n ; i++){
//         for ( int j = 0 ; j < n; j++){
//             if((*compare)( data[i] , data[j] ))
//                 swap(data[i],data[j]);
//         }
//     }
// }