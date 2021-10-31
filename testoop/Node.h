#ifndef NODE_H
#define NODE_H
#include "Word.h"
#include <iostream>
#include <string>

using namespace std;

class Node {
    public:
        Word value;
        Node *next;
    public:
        //Node();
        friend Node *createNode(Word &);
        friend Node *createNode(string word , string type , string mean , string example);
};

Node *createNode(Word &W){
    Node *p = new Node;
    p->value = W;
    p->next  = NULL;
    return p;
}
Node *createNode(string word , string type , string mean , string example){
    Node *p = new Node;
    p->value.setWord(word);
    p->value.setType(type);
    p->value.setMean(mean);
    p->value.setExample(example);
    p->next = NULL;
    return p;
}

#endif
