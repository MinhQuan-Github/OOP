#include <string>
#include <iostream>
#include "Hocsinh.h"
#include "Danhsach.h"

using namespace std;

int main (){
    Hocsinh H1("Minh Quan" , 10 , 9);
    Hocsinh H2("Quoc Bao" , 9 , 9);
    cout << H1;
    Danhsach D1;
    D1 = D1 + H1 + H2;
    cout << D1;
    D1 = D1 - H1;
    cout << D1;
}