#ifndef SETOFINTEGER_H
#define SETOFINTEGER_H
#include <iostream>
#include <iomanip>

using namespace std;

class SetOfInteger {
    private:
        int n;
        int *data;
    public:
        SetOfInteger(int n = 0);                // Hàm dựng mặc định khởi tạo số lượng phần tử = 0     
        SetOfInteger(int *data);                // Hàm dựng sao chép từ một mảng cho trước
        SetOfInteger(const SetOfInteger &);     // Hàm dựng sao chép từ một đối tượng khác
        ~SetOfInteger(){ delete [] data ; }     // Hàm huỷ , giải phóng bộ nhớ
        SetOfInteger operator +(const SetOfInteger &);  // Hàm hợp giữa hai tập hợp
        SetOfInteger operator -(const SetOfInteger &);  // Hàm hiệu giữa hai tập hợp
        SetOfInteger operator *(const SetOfInteger &);  // Hàm giao giữa hai tập hợp
        SetOfInteger operator +(int data);      // Hàm thêm một giá trị vào tập hợp
        SetOfInteger operator -(int data);      // Hàm bỏ một giá trị ra khỏi tập hợp
        const SetOfInteger &operator =(const SetOfInteger &);   //Hàm gán giữa hai tập hợp 
        int &operator [] (int i);       // Hàm lấy phần tử
        bool operator () (int data);    // Hàm kiểm tra phần tử có tồn tại trong tập hợp hay không 
        friend ostream &operator <<(ostream &out , const SetOfInteger &);   // Hàm xuất tập hợp
};


#endif