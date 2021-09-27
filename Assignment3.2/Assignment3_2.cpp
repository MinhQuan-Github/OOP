#include "Complex.h"
#include <iostream>

using namespace std;

Complex C1 , C2;

int main () {
    C1.setComplex(1,2);
    cout <<"Số phức C1 : "<< C1 << endl;
    C2.setComplex(3);
    cout <<"Số phức C2 : "<< C2 << endl;
    
    Complex C3 , C4;
    cout <<"Nhập số phức C3 : " <<endl ; cin >> C3;
    cout <<"Nhập số phức C4 : " <<endl ; cin >> C4;
    cout <<"C3 = " << C3 << " và C4 = " << C4 << endl;
    cout <<"=> Độ lớn của số phức C3 là " << C3.module() << endl;
    cout <<"=> Độ lớn của số phức C4 là " << C4.module() << endl;
    cout <<"=> Tổng hai số phức C3 và C4 là " << C3 + C4 << endl;
    cout <<"=> Hiệu hai số phức C3 và C4 là " << C3 - C4 << endl;
    cout <<"=> Tích hai số phức C3 và C4 là " << C3 * C4 << endl;
    cout <<"=> Thương hai số phức C3 và C4 là " << C3 / C4 << endl;
    if(C3.compare(C4) == 1) cout << "C3 lớn hơn C4" << endl ;
    if(C3.compare(C4) == -1) cout << "C3 bé hơn C4" << endl;
    if(C3.compare(C4) == 0) cout << "C3 bằng C4" << endl;
    return 0;
}