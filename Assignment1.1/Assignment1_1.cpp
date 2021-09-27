// 1/ Viết chương trình cho phép thực hiện các thao tác trên kiểu struct Date gồm ngày, tháng, năm:

#include <iostream>

using namespace std;

struct Date{
    int Ngay , Thang , Nam;
};

istream &operator >>(istream &in, Date &a);             // Hàm toán tử >>
ostream &operator <<(ostream &out,const Date &a);       // Hàm toán tử <<
const char *get_day(int ngay , int thang , int nam);    // Hàm lấy thứ
Date operator ++(Date a);                               // Hàm toán tử ++
Date operator --(Date a);                               // Hàm toán tử --
bool operator >(Date a , Date b);                       // Hàm toán tử >
bool operator <(Date b , Date a);                       // Hàm toán tử <
bool operator == (Date b , Date a);                     // Hàm toán tử ==
bool operator != (Date b , Date a);                     // Hàm toán tử !=
bool nam_nhuan(int a);                                  // kiem tra nam nhuan


//--------------------------------------------------------------------------------------------------------------------------------//


int main(){
    //---------------------------------Hàm toán tử nhập, xuất 01 ngày Date (>>, <<)-------------------------------------
    Date D1;
    cout << "Nhap vao cac thong tin ngay thu 1 : " << endl;
    cin >> D1;
    cout << " => " << D1 ;

    //---------------------------------------Hàm xác định thứ trong tuần.-----------------------------------------------
    cout << " => " << get_day(D1.Ngay,D1.Thang,D1.Nam) << endl ;
    
    //----------------------------------Hàm toán tử ++, -- để tăng, giảm 01 ngày----------------------------------------
    cout << "Ngày hôm sau : "   << ++D1 << endl;
    cout << "Ngày hôm trước : " << --D1 << endl;
    
    //-------------------------------Hàm toán tử so sánh: <, >, ==, != giữa hai ngày.-----------------------------------
    Date D2;
    cout << "Nhap vao cac thong tin ngay thu 2 : " << endl;
    cin >> D2;
    cout << " => " << D2 ;
    if (D1 > D2) cout << " => Ngay thu 1 lon hon ngay 2"<<endl;
    if (D1 < D2) cout << " => Ngay thu 2 lon hon ngay 1"<<endl;
    if (D1 == D2) cout <<" => Ngay thu 1 bang ngay thu 2"<<endl;
    if (D1 != D2) cout <<" => Ngay thu 1 khac ngay thu 2"<<endl;
    return 0;
}

bool nam_nhuan(int a) {                                 // kiem tra nam nhuan
    if (((a % 4)==0) && ((a % 100)!=0)){
        return true;
    } else if ((a % 400)==0){
        return true;
    }else {
        return false;
    }
    return true;
}

istream &operator >>(istream &in, Date &a){             // Hàm toán tử >>
    cout << "Nhap ngay   (1 <= ngay <= 31) : "; in >> a.Ngay;
    cout << "Nhap thang (1 <= thang <= 12) : " ; in >> a.Thang;
    cout << "Nhap nam            (nam > 0) : " ; in >> a.Nam;
    return in;
}

ostream &operator <<(ostream &out, const Date &a){      // Hàm toán tử <<
    cout << a.Ngay << "/" << a.Thang << "/" << a.Nam << endl;
    return out;
}

const char *get_day(int ngay , int thang , int nam){    // Hàm lấy thứ
    int k ;
    k = (ngay + ((153 * (thang + 12 * ((14 - thang) / 12) - 3) + 2) / 5) +
    (365 * (ngay + 4800 - ((14 - thang) / 12)))
    +((nam + 4800 - ((14 - thang) / 12)) / 4) -
    ((nam + 4800 - ((14 - thang) / 12)) / 100) +
    ((nam + 4800 - ((14 - thang) / 12)) / 400)  - 32045) % 7;
    const char *weekday[] = {"Thu 2" , "Thu 3" , "Thu 4" , "Thu 5" , "Thu 6" , "Thu 7" , "Chu Nhat"};
    return weekday[k];
}

Date operator ++(Date a){           // Hàm toán tử ++ để tăng 1 ngày
    switch (a.Thang) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            if(a.Ngay == 31) {
                a.Ngay = 1;
                a.Thang ++;
            } else a.Ngay ++;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(a.Ngay == 30) {
                a.Ngay = 1;
                a.Thang ++;
            } else a.Ngay ++;
            break;
        case 12:
            if(a.Ngay == 31) {
                a.Nam ++;
                a.Ngay = 1;
                a.Thang = 1;
            } else a.Ngay ++;
            break;
        case 2:
            if(nam_nhuan(a.Nam) == true) {
                if(a.Ngay == 29) {
                    a.Ngay = 1;
                    a.Thang = 3;
                } else a.Ngay ++;
            } else {
                if(a.Ngay == 28) {
                    a.Ngay = 1;
                    a.Thang = 3;
                } else a.Ngay ++;
            }
            break;
    }
    return a;
}

Date operator --(Date a){           // Hàm toán tử -- để lùi 1 ngày
    switch (a.Thang) {
        case 2:
        case 4:
        case 6:
        case 8:
        case 9:
        case 11:
            if(a.Ngay == 1) {
                a.Ngay = 31;
                a.Thang --;
            } else a.Ngay --;
            break;
        case 5:
        case 7:
        case 10:
        case 12:
            if(a.Ngay == 1) {
                a.Ngay = 30;
                a.Thang --;
            } else a.Ngay --;
            break;
        case 1:
            if(a.Ngay == 1) {
                a.Nam --;
                a.Ngay = 31;
                a.Thang = 12;
            } else a.Ngay --;
            break;
        case 3:
            if(nam_nhuan(a.Nam) == true) {
                if(a.Ngay == 1) {
                    a.Ngay = 29;
                    a.Thang = 2;
                } else a.Ngay --;
            } else {
                if(a.Ngay == 1) {
                    a.Ngay = 28;
                    a.Thang = 2;
                } else a.Ngay --;
            }
            break;
    }
    return a;
}

bool operator >(Date b , Date a){   // Hàm toán tử >
    if (b.Nam > a.Nam) return true;
    else if (b.Nam < a.Nam) return false;
    else {
        if (b.Thang > a.Thang) return true;
        else if (b.Thang < a.Thang) return false;
        else {
            if (b.Ngay > a.Ngay) return true;
            else return false;
        }
    }
    return false;
}

bool operator <(Date b , Date a){   // Hàm toán tử <
    if (b.Nam < a.Nam) return true;
    else if (b.Nam > a.Nam) return false;
    else {
        if (b.Thang < a.Thang) return true;
        else if (b.Thang > a.Thang) return false;
        else {
            if (b.Ngay < a.Ngay) return true;
            else return false;
        }
    }
    return false;
}

bool operator == (Date b , Date a){ // Hàm toán tử ==
    if ((b.Nam == a.Nam) && (b.Thang == a.Thang) && (b.Ngay == a.Ngay)) return true;
    return false;
}

bool operator != (Date b , Date a){ // Hàm toán tử !=
    if ((b.Nam == a.Nam) && (b.Thang == a.Thang) && (b.Ngay == a.Ngay)) return false;
    return true;
}
