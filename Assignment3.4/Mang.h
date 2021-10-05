

#ifndef MANG_H
#define MANG_H

bool descending(int l, int r);
bool ascending(int l , int r);
void swap(int &num1, int &num2);

class Mang {
    private:
        int number;
        int *data;
    public:
        Mang(int n = 0);    // Hàm dựng mặc định kiêm hàm khởi tạo các phần tử bằng 0
        Mang(const Mang &); // Khởi tạo từ một đối tượng IntArray khác
        ~Mang();            // Hàm huỷ
        void setArr(int n); // Khởi tạo từ một mảng int [ ] với kích thước cho trước.
        void input();       // Hàm nhập
        void output();      // Hàm xuất
        int getSize();      // hàm lấy kích thước mảng
        void getValue();    // Lấy giá trị tại vị trí bất kì 
        void updateValue(); // Gán giá trị cho phần tử taị vị trí bất kì 
        void find();        // Hàm tìm phần tử nào đó trong mảng 
        void sort(bool(*compare)(int , int));        // sắp xếp 
};

#endif
