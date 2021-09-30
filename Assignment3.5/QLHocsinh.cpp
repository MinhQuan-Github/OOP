#include "Hocsinh.h"
#include <iostream>
#include "DSHS.h"
int main(){
    DSHS ds(4);
    cin >> ds;
    cout<<"Danh sach hoc sinh vua nhap:"<<endl;
    cout << ds << endl << endl;
    ds.sort(ascending);
    cout << ds;
    return 0;
}