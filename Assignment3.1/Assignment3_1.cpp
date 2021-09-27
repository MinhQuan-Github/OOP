#include <iostream>
#include "Phanso.h"

using namespace std;

Phanso F,G;

int main () {
    int numerator , denominator ; 
    cout << "Nhap tu so = " ; cin >> numerator;
    cout << "Nhap mau so = "; cin >> denominator;
    F.createFraction(numerator,denominator);
    F.output();
    cout << "Phân số này có tử số bằng " << F.getNumerator(F)<<endl;
    cout << "Phân số này có mẫu số bằng " << F.getDenominator(F)<<endl;

    cout << "Gán giá trị của phân số : " << endl;
    G = F; // gán giá trị của phân số F cho G
    G.output();

    cout << "Nghịch đảo phân số : " << endl;
    G.inverse(F);
    G.output();

    cout << "Rút gọn phân số : " << endl;
    G.compact(F);
    G.output();

    Phanso C,D;
    cout <<"Khởi tạo phân số C : "<<endl; 
    int C1 , C2;
    cout << "Nhap tu so = " ; cin >> C1;
    cout << "Nhap mau so = "; cin >> C2;
    C.createFraction(C1,C2);
    C.output();

    cout <<"Khởi tạo phân số D : "<<endl;
    int D1 , D2;
    cout << "Nhap tu so = " ; cin >> D1;
    cout << "Nhap mau so = "; cin >> D2;
    D.createFraction(D1,D2);
    D.output();

    cout << "Phep cong hai phan so C và D bằng  ";
    G.plusFraction(C,D);

    cout << "Phep tru hai phan so C và D bằng  ";
    G.subtractFraction(C,D);

    cout << "Phep nhan hai phan so C và D bằng  ";
    G.multipleFraction(C,D);

    cout << "Phep chia hai phan so C và D bằng  ";
    G.divideFraction(C,D);

    if (G.compare(C,D) == 1) cout << "phân số C lớn hơn phân số D";
    if (G.compare(C,D) == -1) cout << "phân số C bé hơn phân số D";
    if (G.compare(C,D) == 0) cout << "phân số C bằng phân số D";

    return 0;
}