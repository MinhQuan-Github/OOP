#include "Matrix.h"
#include <iostream>

using namespace std;

int main () {
    Matrix M1(4);
    cin >> M1;
    cout << M1;
    Matrix M2(4);
    cin >> M2;
    cout << M2;
    Matrix M = M1 * M2;
    cout << M;
    cout << M1 + M2;
    cout << M1 - M2;
    return 0;
}