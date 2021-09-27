#include <iostream>
#include <iomanip>
#include "Hocsinh.h"

using namespace std;

int main () {
    Hocsinh A("Duong Quoc Bao" , 9 , 10);
    cout << A;

    Hocsinh B = A;
    B.updateHoten();
    cout << B;

    Hocsinh C; cout <<"Khởi tạo học sinh C : " << endl;
    cin >> C;
    cout << C;

    cout << "Họ tên của học sinh C : " << C.getHoten() << endl;
    cout << "Điểm văn của học sinh C : " << C.getVan() << endl;
    cout << "Điểm toán của học sinh C : " << C.getToan() << endl;
    cout << "Điểm trung bình của học sinh C : " << fixed << setprecision(2)<< C.diemtb() << endl;
    
    if (C.xeploai() == 1) cout << " => Hoc luc YEU " << endl;
    if (C.xeploai() == 2) cout << " => Hoc luc TRUNG BINH " << endl;
    if (C.xeploai() == 3) cout << " => Hoc luc KHA " << endl;
    if (C.xeploai() == 4) cout << " => Hoc luc GIOI " << endl;
    return 0;
}