// 2/ Viết chương trình cho phép thực hiện các thao tác trên kiểu struct học sinh để quản lý danh sách học sinh.

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct hocsinh{
    string hoten;
    float toan,van;
};

istream &operator >>(istream &in, hocsinh &a);                // Hàm toán tử >>
ostream &operator <<(ostream &out, const hocsinh &a);         // Hàm toán tử <<
float diemtb (hocsinh &a);                                    // Hàm tính điểm trung bình
int xeploai (hocsinh &a);                                     // Hàm xếp loại học lực
bool operator >(hocsinh a , hocsinh b);                       // Hàm toán tử >
bool operator <(hocsinh a , hocsinh b);                       // Hàm toán tử <


int main () {
    //-------------------------------Nhập, xuất thông tin học sinh. (toán tử>>, <<)---------------------------------------
    hocsinh HS1;
    cout << "Nhap thong tin hoc sinh 1 : " << endl;
    cin >> HS1;
    cout << HS1 << endl;
    
    //----------------------------------Tính điểm trung bình của mỗi học sinh.--------------------------------------------
    cout << "Diem trung binh hoc sinh 1 : " << fixed << setprecision(2) << diemtb(HS1)<<endl;
    
    //-----------------------------------------Xếp loại theo tiêu chí-----------------------------------------------------
    // Giỏi (>= 8.0), Khá (>= 7.0).
    //Trung bình (>= 5.0), Yếu (< 5).
    if (xeploai(HS1) == 1) cout << " => Hoc luc YEU " << endl;
    if (xeploai(HS1) == 2) cout << " => Hoc luc TRUNG BINH " << endl;
    if (xeploai(HS1) == 3) cout << " => Hoc luc KHA " << endl;
    if (xeploai(HS1) == 4) cout << " => Hoc luc GIOI " << endl;
    
    //--------Yêu cầu định nghĩa toán tử so sánh <, > để so sánh giữa 2 hồ sơ học sinh dựa trên điểm trung bình.----------
    hocsinh HS2;
    cout << "Nhap thong tin hoc sinh 2 : " << endl;
    cin >> HS2;
    cout << HS2<<endl;
    if (HS1 > HS2) cout <<"Ho so hoc sinh 1 tot hon hoc sinh 2"<<endl;
    else if (HS1 < HS2) cout <<"Ho so hoc sinh 2 tot hon hoc sinh 1"<<endl;
    else cout << "Ho so 2 hoc sinh nhu nhau"<< endl;
    return 0;
}

inline istream &operator >>(istream &in, hocsinh &a){             // Hàm toán tử >>
    cin.ignore(); fflush(stdin);
    cout << "Nhap ho va ten : " ; getline(cin , a.hoten);
    cout << "Nhap diem van  : " ; in >> a.van;
    cout << "Nhap diem toan : " ; in >> a.toan;
    return in;
}

ostream &operator <<(ostream &out,const hocsinh &a){      // Hàm toán tử <<
    cout << "------------------------------------------"<<endl;
    cout << "Ho va ten : " << a.hoten << endl;
    cout << "Diem van  : " << a.van   << endl;
    cout << "Diem toan : " << a.toan  << endl;
    return out;
}

float diemtb (hocsinh &a){                                 // Hàm tính điểm trung bình
    return (a.toan + a.van)/2;
}

int xeploai (hocsinh &a){                                  // Hàm xếp loại học lực
    if (diemtb(a) >= 8) return 4;
    else if (diemtb(a) >= 7) return 3;
    else if (diemtb(a) >= 5) return 2;
    return 1;
}

bool operator >(hocsinh a , hocsinh b){
    if (diemtb(a) > diemtb(b)) return true;
    return false;
}

bool operator <(hocsinh a , hocsinh b){
    if (diemtb(a) < diemtb(b)) return true;
    return false;
}