#include "HashTable.h"
#include "Word.h"
#include <iostream>
#include <string>
#define SIZE 1000

using namespace std;

int main(){
    Node *dic[SIZE];
    HashTable H;
    H.initHash(dic);
    // Word k("hello" , "hi" , "sd" , "dsd");
    // H.Insert(k);
    H.display();
    return 0;
}