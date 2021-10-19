#include "Hocsinh.h"
#include <iostream>
#include "DSHS.h"
using namespace std; 
int main(){
    DSHS ds;
    Hocsinh hs1("bao",10,10);
    Hocsinh hs2("tuan",8,9);
    ds=ds+hs1+hs2;
    cout << ds;
    return 0;
}