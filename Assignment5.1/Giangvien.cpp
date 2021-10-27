#include "Giangvien.h"
#include <iostream>
#include <string>
using namespace std;

Giangvien::Giangvien(string hoten , string bomon , int sobaibao):Ungcuvien(hoten){
    this->bomon = bomon;
    this->sobaibao = sobaibao;
}
istream &operator >> (istream &in , Giangvien &S){
    cout << "NHẬP THÔNG TIN GIẢNG VIÊN : " << endl;
    cin.ignore();
    cout << " - Họ và tên       : " ; getline(cin , S.hoten);
    cout << " - Bộ môn          : " ; getline(cin , S.bomon);
    cout << " - Số bài báo      : " ; cin >> S.sobaibao;
    return in;
}
ostream &operator << (ostream &out , const Giangvien &S){
    cout << "   | Họ và tên     : " << S.hoten << endl;
    cout << "=> | Bộ môn        : " << S.bomon << endl;
    cout << "   | Số bài báo    : " << S.sobaibao << endl;
    return out;
}
bool duocThuong(const Giangvien &S){
    return (S.sobaibao >= 3)? true : false;
}