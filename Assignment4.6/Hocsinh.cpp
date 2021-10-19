#include <string>
#include <iostream>
#include "Hocsinh.h"

using namespace std;

Hocsinh::Hocsinh(string hoten , int van , int toan){
    //Hocsinh *this = new Hocsinh;
    this->hoten = hoten;
    this->van   = van;
    this->toan  = toan;
}

Hocsinh::Hocsinh(const Hocsinh &k){
    //Hocsinh *temp = 
    this->van = k.van;
    this->toan = k.toan;
    this->hoten =k.hoten;
}

Hocsinh::~Hocsinh(){};

istream &operator >>(istream &in, Hocsinh &a){                   // Hàm toán tử >>
    //cin.ignore(); fflush(stdin);
    cout << "Nhap ho va ten : " ; getline(cin , a.hoten);
    cout << "Nhap diem van  : " ; in >> a.van;
    cout << "Nhap diem toan : " ; in >> a.toan;
    return in;
}

ostream &operator <<(ostream &out,const Hocsinh &a){             // Hàm toán tử <<
    cout << "------------------------------------------"<<endl;
    cout << "Ho va ten : " << a.hoten << endl;
    cout << "Diem van  : " << a.van   << endl;
    cout << "Diem toan : " << a.toan  << endl;
    return out;
}

string Hocsinh::getHoten(){
    return this->hoten;
}

float Hocsinh::getVan(){
    return this->van;
}

float Hocsinh::getToan(){
    return this->toan;
}

void Hocsinh::updateHoten(){
    cout << " Nhập tên cần gán cho học sinh : ";
    string temp; getline(cin,temp);
    this->hoten = temp;
}

void Hocsinh::updateVan(){
    cout << " Nhập điểm văn cần gán cho học sinh : ";
    float temp; cin >> temp;
    this->van = temp;
}

void Hocsinh::updateToan(){
    cout << " Nhập điểm toán cần gán cho học sinh : ";
    float temp; cin >> temp;
    this->toan = temp;
}

float Hocsinh::diemtb (){                                 // Hàm tính điểm trung bình
    return (toan + van)/2;
}

void Hocsinh::setHocsinh(string hoten , int van , int toan){
    this->hoten = hoten;
    this->van = van;
    this->toan = toan;
}             


int Hocsinh::xeploai (){                                  // Hàm xếp loại học lực
    Hocsinh temp;
    temp.hoten = this->hoten;
    temp.van   = this->van;
    temp.toan  = this->toan;                               
    if (temp.diemtb() >= 8) return 4;
    else if (temp.diemtb() >= 7) return 3;
    else if (temp.diemtb() >= 5) return 2;
    return 1;
}

bool operator >(Hocsinh &a , Hocsinh &b){
    if (a.diemtb() > b.diemtb()) return true;
    return false;
}

bool operator <(Hocsinh &a , Hocsinh &b){
    if (a.diemtb() < b.diemtb()) return true;
    return false;
}

bool operator ==(Hocsinh &a , Hocsinh &b){                // Hàm toán tử ==
    if (a.diemtb() == b.diemtb()) return true;
    return false;
}
const Hocsinh &Hocsinh::operator = (const Hocsinh &k){                    // Hàm toán tử =
    this->van = k.van;
    this->toan = k.toan;
    this->hoten =k.hoten;    
    return *this;
}
bool operator >=(Hocsinh &a , Hocsinh &b){               // Hàm toán tử >
    if (a.diemtb() >= b.diemtb()) return true;
    return false;
}
bool operator <=(Hocsinh &a , Hocsinh &b){               // Hàm toán tử <
    if (a.diemtb() <= b.diemtb()) return true;
    return false;
}
bool operator !=(Hocsinh &a , Hocsinh &b){               // Hàm toán tử ==
    if (a.diemtb() != b.diemtb()) return true;
    return false;
}


