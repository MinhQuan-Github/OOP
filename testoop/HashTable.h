#ifndef HASHTABLE_H
#define HASHTABLE_H
#include<iostream>
#include<string>
#include "Word.h"
//#include "Node.h"
#define HT_SIZE 1000 // Hash Table Size
using namespace std;

struct Node{
    Word value;
    Node *next;
};

Node *createNode(Word &W){
    Node *p = new Node;
    p->value = W;
    p->next  = NULL;
    return p;
}
// Node *createNode(string word , string type , string mean , string example){
//     Node *p = new Node;
//     p->value.setWord(word);
//     p->value.setType(type);
//     p->value.setMean(mean);
//     p->value.setExample(example);
//     p->next = NULL;
//     return p;
// }

class HashTable {
    protected:
        Node *DICTIONARY[HT_SIZE]; 
    public:
        void initHash(Node *head[]);
        int  HashFunc(string word);   
        void Insert(Word &n);            
        Node *Find(string word);
        void display();
};

void HashTable::initHash(Node *head[]){
    for( int i = 0 ; i < HT_SIZE ; i++){
        head[i] = NULL;
    }
} 
int HashTable::HashFunc(string word){
	int sum = 0;
    for(int i =0;i< word.size();i++){
    	sum+=int(word[i]);
	}
	return sum%HT_SIZE;
};
void HashTable::Insert(Word &n){
    int index = HashFunc(n.getWord());
    Node *r = this->DICTIONARY[index];
    Node *prev = NULL;
    while (r != NULL && r->value.getWord().size() < n.getWord().size()){
        prev = r;
        r = r->next;
    }
    Node *p = createNode(n);
    if (prev == NULL) {
        this->DICTIONARY[index] = p;
        p->next = r;
    } 
    else if (r == NULL){
        prev->next = p;
    }
    else {
        p->next = r;
        prev->next = r;
    }
}
Node *HashTable::Find(string word){
    int index = HashFunc(word);
    Node *r = this->DICTIONARY[index];
    while (r != NULL && r->value.getWord() != word)
        r = r->next;
    return r;
}	
void HashTable::display(){
    for (int i = 0 ; i < HT_SIZE ; i++)
        if(this->DICTIONARY[i] != NULL) {
            cout << "=== BUCKET " << i << "===" << endl;
            Node *p = this->DICTIONARY[i];

            while (p != NULL) {
                p->value.display();
                p = p->next;
            }
            cout << endl;
        }
}
 
           
#endif