#include "Sinhvien.h"
#include "Giangvien.h"
#include <iostream>
#include <string>
using namespace std;

int main () {
    Sinhvien S1("Minh Quan" , "20T2" , 8);
    Sinhvien S2;
    cin >> S2;
    cout <<S1<<S2;
    Giangvien G1("My Hanh" , "Lập tình HĐT" , 20);
    Giangvien G2;
    cin >> G2;
    cout << G1 << G2;
    return 0;
}