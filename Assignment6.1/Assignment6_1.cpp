#include<iostream>
#include<iomanip>
#include<math.h>
#define PI 3.14

using namespace std;

class Hinh {
    protected:
        float a;
    public:
        Hinh(){}
        Hinh(float a):a(a){}
        virtual double ChuVi(){return 0;}
        virtual double DienTich(){return 0;}
        virtual double TheTich(){return 0;}
};

class Hinh2D : public Hinh {
    public:
        Hinh2D(float a) : Hinh(a){}
        virtual double Chuvi(){return 0;}
        virtual double DienTich(){return 0;}
};

class Hinh3D : public Hinh {
    public:
        Hinh3D(float a) : Hinh(a){}
        virtual double Dientich(){return 0;}
        virtual double TheTich(){return 0;}
};

class HinhTamGiacDeu : public Hinh2D {
    public:
        HinhTamGiacDeu(float a):Hinh2D(a){}
        double ChuVi(){ return 3 * a ;}
        double DienTich(){return a * a * sqrt(3) / 4 ;}
};

class HinhTron : public Hinh2D {
    public:
        HinhTron(float rad):Hinh2D(rad){}
        double ChuVi(){return 2 * PI * a;}
        double DienTich(){return PI * a * a;}
};

class HinhVuong : public Hinh2D {
    public:
        HinhVuong(float a):Hinh2D(a){}
        double ChuVi(){return a * 4;}
        double DienTich(){return a * a;}
};

class HinhLapPhuong : public Hinh3D {
    public:
        HinhLapPhuong(float a):Hinh3D(a){}
        double DienTich(){return 6 * a * a;}
        double TheTich(){return a * a * a;}
};  

class HinhCau : public Hinh3D {
    public:
        HinhCau(float rad):Hinh3D(rad){}
        double DienTich(){return 4 * PI * a * a;}
        double TheTich(){return 4 / 3 * PI * a * a * a;}
};

int main(){
    Hinh *H[5];
    H[0] = new HinhTron(5);
    H[1] = new HinhVuong(4);
    H[2] = new HinhTamGiacDeu(3);
    H[3] = new HinhCau(6);
    H[4] = new HinhLapPhuong(10);
    cout << "Chu vi : " << endl;
    cout << H[0]->ChuVi() << endl << H[1]->ChuVi() << endl << H[2]->ChuVi() << endl;
    cout << "Dien tich : " << endl;
    cout << H[0]->DienTich() << endl << H[1]->DienTich() << H[2]->DienTich();
    return 0;
}

