#include "Sinhvien.h"
#include <iostream>
#include <string>
using namespace std;

Sinhvien::Sinhvien(string hoten , string lop , float dtb):Ungcuvien(hoten){
    this->lop = lop;
    this->dtb = dtb;
}
istream &operator >> (istream &in , Sinhvien &S){
    cout << "NHẬP THÔNG TIN SINH VIÊN : " << endl;
    cin.ignore();
    cout << " - Họ và tên       : " ; getline(cin ,S.hoten);
    cout << " - Lớp             : " ; getline(cin , S.lop);
    cout << " - Điểm trung bình : " ; cin >> S.dtb;
    return in;
}
ostream &operator << (ostream &out , const Sinhvien &S){
    cout << "   | Họ và tên       : " << S.hoten << endl;
    cout << "=> | Lớp             : " << S.lop << endl;
    cout << "   | Điểm trung bình : " << S.dtb << endl;
    return out;
}
bool duocThuong(const Sinhvien &S){
    return (S.dtb >= 8)? true : false;
}