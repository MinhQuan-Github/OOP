#include "Hocsinh.h"
#include <iostream>
#include <iomanip>
using namespace std;

int Hocsinh::count = 0;//định nghĩa thành viên tĩnh 

Hocsinh::Hocsinh(string ten, double t, double v): ht(ten), toan(t),van(v){ 
    count++;
}

Hocsinh::Hocsinh(const Hocsinh &x){
    ht = x.ht;
    toan = x.toan;
    van = x.van;
    dtb = x.dtb;
    xl = x.xl;
    count++;
}

void Hocsinh::Nhap(){
    cout<<"Nhap ho ten hoc sinh:";
    cin>>ht;
    cout<<"Nhap diem mon toan:"; 
    cin>>toan;
    cout<<"Nhap diem mon van:"; 
    cin>>van;
    dtb = (toan + van)/2;
    xl = (dtb<5)?"Yeu":(dtb<6.5)?"Trung binh":(dtb<8)?"Kha":"Gioi";
}

void Hocsinh::Xuat() const{
    cout<<setw(20)<<ht<<setw(8)<<toan<<setw(8)<<van<<setw(8)<<dtb<<setw(15)<<xl<<endl;
}

istream &operator >>(istream &in, Hocsinh &a){             // Hàm toán tử >>
    cin.ignore();
    cout << "Nhap ho va ten : " ; getline(cin , a.ht);
    cout << "Nhap diem van  : " ; in >> a.van;
    cout << "Nhap diem toan : " ; in >> a.toan;
    a.dtb = (a.toan + a.van)/2;
    a.xl = (a.dtb < 5)?"Yeu":(a.dtb < 6.5)?"Trung binh":(a.dtb < 8)?"Kha":"Gioi";
    return in;
}

ostream &operator <<(ostream &out,const Hocsinh &a){      // Hàm toán tử <<
    cout << setw(20) << a.ht << setw(8) << a.toan << setw(8) << a.van << setw(8) << a.dtb << setw(15) << a.xl << endl;
    return out;
}

bool operator >(const Hocsinh &a , const Hocsinh &b ){
    if (a.dtb > b.dtb) return true;
    return false;
}

bool operator <(const Hocsinh &a , const Hocsinh &b ){
    if (a.dtb < b.dtb) return true;
    return false;
}

