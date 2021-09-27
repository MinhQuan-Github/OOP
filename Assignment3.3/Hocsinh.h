#include <string>
#include <iostream>

using namespace std;

#ifndef HOCSINH_H
#define HOCSINH_H

class Hocsinh {
    private :
        string hoten;
        float van , toan;
    public:
        Hocsinh(string hoten = "AAA", int van = -1 , int toan = -1);    // Hàm dựng mặc định 
        Hocsinh(const Hocsinh &);                                       // Hàm khởi tạo từ một học sinh khác
        ~Hocsinh();                                                     // Hàm huỷ , thu hồi bộ nhớ
        friend istream &operator >>(istream &in, Hocsinh &a);           // Hàm nhap
        friend ostream &operator <<(ostream &out, const Hocsinh &a);    // Hàm xuất 
        string getHoten();                               // Lấy họ tên học sinh
        float getVan();                                  // Lấy điểm văn học sinh
        float getToan();                                 // Lấy điểm toán học sinh
        void updateHoten();                                             // Gán họ tên học sinh
        void updateVan();                                               // Gán điểm văn học sinh
        void updateToan();                                              // gán điểm toán học sinh
        void setHocsinh(string hoten , int van , int toan);             // Khởi tạo hàm
        float diemtb ();                                                // Hàm tính điểm trung bình
        int xeploai ();                                                 // Hàm xếp loại học lực
        friend bool operator >(Hocsinh a , Hocsinh b);                  // Hàm toán tử >
        friend bool operator <(Hocsinh a , Hocsinh b); 
};

#endif