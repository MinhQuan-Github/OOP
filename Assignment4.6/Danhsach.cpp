#include <string>
#include <iostream>
#include "Hocsinh.h"
#include "Danhsach.h"

using namespace std;

Danhsach::Danhsach(){
    this->head = this->tail = NULL;
}
Danhsach::Danhsach(const Danhsach &D){
    // Node *i = this->head;
    // Node *j = D.head;
    // while (j != NULL){
    //     i->data = j->data;
    //     i = i->next;
    //     j = j->next;
    // }
    this->head = D.head;
    this->tail = D.tail;
}
Node *createNode(Hocsinh &H){
    Node *p = new Node;
    p->data = H;
    p->next = NULL;
    return p;
}
Danhsach Danhsach::operator +(Hocsinh &H){
    Node *p = createNode(H);
    if (this->head == NULL){
        this->head = this->tail = p;
    } else {
        this->tail->next = p;
        this->tail = p;
    }
    return *this;
}
Danhsach Danhsach::operator -(Hocsinh &H){
    Node *i;
    if (this->head->data == H) {
        this->head = this->head->next;
        return *this;
    }
    for (i = this->head ; i != NULL ; i=i->next){
        if ( i->next->data == H ) {
            i->next = i->next->next;
            return *this;
        } 
    }
    return *this;
}
const Danhsach &Danhsach::operator =(const Danhsach &D){
    // Node *i = this->head;
    // Node *j = D.head;
    // while (j != NULL){
    //     i->data = j->data;
    //     i = i->next;
    //     j = j->next;
    // }
    this->head = D.head;
    this->tail = D.tail;
    return *this;
}
Hocsinh Danhsach::operator () (int x){
    int count = 0;
    Node *p = this->head;
    while (p != NULL){
        if ( count != x ) return p->data;
        count++;
    }
    return this->head->data;
}
ostream &operator << (ostream &out , const Danhsach &D){
    Node *p = D.head;
    cout << "------------------------------- DANH SÁCH HỌC SINH -------------------------------"<<endl;
    while (p != NULL){
        cout << p->data;
        p = p->next;
    }
    return out;
}
void delDanhsach(Hocsinh &D){
    Node *p = createNode(D);
    if (p->next != NULL) delDanhsach(p->next->data);
    delete p;
}
Danhsach::~Danhsach(){
    if(this->head != NULL) delDanhsach(this->head->data);
}