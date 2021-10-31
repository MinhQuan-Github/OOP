#include "Ground.h"
#include "Rectangle.h"
#include "Trapezoid.h"
#include "Triangle.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    Ground *G[100];
    int N = 0;
    string ID;
    long long price;
    double area;
    double totalPrice;
    int kind;
    char select;
    do {
        cout << "ID    : "; cin >> ID;
        cout << "Price : "; cin >> price;
        cout << "1/ Triangle.\n2/Trapezoid.\n3/Rectangle.\n";
        cout << "Select one of these : " ; cin >> kind;
        while (kind != 1 && kind != 2 && kind != 3) {
            cout << "Xin mời chọn lại hoặc nhập '0' để kết thúc !! Your select : ";
            cin >> kind;
            kind = int(kind);
            if (kind == 0) {
                select = 'K';
                break;
            }
        }
        if (kind == 1) {
            float height , bottom;
            cout << "Enter height : "; cin >> height;
            cout << "Enter bottom : "; cin >> bottom;
            G[N++] = new Triangle(ID, price, bottom,height);
        }
        if (kind == 2) {
            float height , width , length;
            cout << "Enter length : "; cin >> length;
            cout << "Enter width  : "; cin >> width;
            cout << "Enter height : "; cin >> height;
            G[N++] = new Trapezoid(ID, price, length, width, height);
        }
        if (kind == 3) {
            float length , width;
            cout << "Enter length : "; cin >> length;
            cout << "Enter width  : "; cin >> width;
            G[N++] = new Rectangle(ID, price, length,width);
        }
        cout << "Bạn có muốn tiếp tục không (C/K) ? : ";
        cin >> select;
        select = toupper(select);
        if((N == 100) || (select == 'K')) break;
    } while (1);
    cout << "Danh sách những miếng đất đang được quản lý bởi công ty : \n";
    for (int i = 0 ; i < N ; i++) G[i]->display();
    return 0;
}