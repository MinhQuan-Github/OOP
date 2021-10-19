#include "SetOfInteger.h"
#include <iostream>
#include <iomanip>

using namespace std;

SetOfInteger::SetOfInteger(int n){                  // Hàm dựng mặc định khởi tạo số lượng phần tử = 0 
    this->n = n;
    this->data = new int [n];
}
SetOfInteger::SetOfInteger(int *data){              // Hàm dựng sao chép từ một mảng cho trước
    this->n = sizeof(*data)/sizeof(int);
    for ( int i = 0 ; i < n ; i++){
        this->data[i] = data[i];
    }
}
SetOfInteger::SetOfInteger(const SetOfInteger &S){  // Hàm dựng sao chép từ một đối tượng khác
    this->n = S.n;
    for ( int i = 0 ; i < n ; i++){
        this->data[i] = S.data[i];
    }
}
void sort(int a[], int n){                          // sắp xếp mảng tăng dần
    for (int i = 0 ; i < n - 1 ; i++){
        for (int j = i + 1 ; j < n ; j++){
            if (a[i] > a[j]) swap(a[i] , a[j]);
        }
    }
}
SetOfInteger SetOfInteger::operator +(const SetOfInteger &S){   // Hàm hợp giữa hai tập hợp
    int number = this->n + S.n;
    int *tmp = new int [number];
    for (int i = 0 ; i < number ; i++){        
        tmp[i] = (i < this->n)? this->data[i] : S.data[i - this->n];
    }
    sort(tmp,number);
    SetOfInteger temp ;
    temp = temp + tmp[0];
    for (int k = 1 ; k < number ; k++)
        if(tmp[k-1] != tmp[k]) temp = temp + tmp[k];
    delete [] tmp;
    return temp;
}
SetOfInteger SetOfInteger::operator -(const SetOfInteger &S){   // Hàm hiệu giữa hai tập hợp
    SetOfInteger P(this->n);
    for (int l = 0 ; l < this->n ; l++) P.data[l] = this->data[l];
    sort(P.data,P.n); int number = P.n;
    for (int i = 0 ; i < number - 1 ; i ++){
        while (P.data[i] == P.data[i+1]){
            for (int j = i ; j < number - 1 ; j++){
                P.data[j] = P.data[j+1];
            }
            number--;
        }
    }
    SetOfInteger temp;
    for (int i = 0 ; i < number ; i++){
        bool check = false;
        for (int j = 0 ; j < S.n ; j++){
            if (P.data[i] == S.data[j]) {
                check = true;
                break;
            }
        }
        if (!check) temp = temp + P.data[i];
    }
    return temp;
}
SetOfInteger SetOfInteger::operator *(const SetOfInteger &S){   // Hàm giao giữa hai tập hợp
    int *tmp = new int [(this->n > S.n)? this->n : S.n];
    int count = 0;
    for (int i = 0 ; i < this->n ; i++)
        for (int j = 0 ; j < S.n ; j++)
            if (this->data[i] == S.data[i]) {
                tmp[count++] = this->data[i];
                break;
            }
    SetOfInteger temp(count);
    for (int m = 0 ; m < count ; m++) temp.data[m] = tmp[m];
    delete [] tmp;
    return temp;
}
SetOfInteger SetOfInteger::operator +(int data){                // Hàm thêm một giá trị vào tập hợp
    SetOfInteger temp(this->n + 1);
    for (int i = 0 ; i < this->n ; i++){
        temp.data[i] = this->data[i];
    }
    temp.data[this->n] = data;
    return temp;
}
SetOfInteger SetOfInteger::operator -(int data){                // Hàm bỏ một giá trị ra khỏi tập hợp
    SetOfInteger temp;
    for (int i = 0 ; i < this->n ; i++) {
        if (this->data[i] != data) temp = temp + this->data[i];
    }
    return temp;
}
const SetOfInteger &SetOfInteger::operator =(const SetOfInteger &S){    //Hàm gán giữa hai tập hợp 
    this->n = S.n;
    delete [] this->data;
    this->data = new int [this->n];
    for ( int i = 0 ; i < n ; i++){
        this->data[i] = S.data[i];
    }
    return *this;
}
int &SetOfInteger::operator [] (int i){                                 // Hàm lấy phần tử
    return this->data[i];
}
bool SetOfInteger::operator () (int data){                              // Hàm kiểm tra phần tử có tồn tại trong tập hợp hay không 
    for (int i = 0 ; i < this->n ; i++){
        if (this->data[i] == data) {
            return true;
        }
    }
    return false;
}
ostream &operator <<(ostream &out , const SetOfInteger &S){             // Hàm xuất tập hợp
    cout << "{ ";
    for (int i = 0 ; i < S.n ; i++){
        cout << S.data[i] << " ";
    }
    cout << "}\n";
    return out;
}
