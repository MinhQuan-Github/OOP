#include "Vecto.h"
#include <iostream>
using namespace std;

int main () {
    Vecto test(4) , V1(4) , V2(4);
    cin >> test;
    cout <<test;

    cin >> V1;
    cin >> V2;

    test = V1 + V2;
    cout << test;

    test = V1 - V2;
    cout << test;

    return 0;
}
