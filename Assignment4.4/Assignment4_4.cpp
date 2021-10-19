#include "Polynomial.h"
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main () {
    Polynomial P1(3);
    cin >> P1;
    Polynomial P2(5);
    cin >> P2;
    cout << "P1 : " << P1;
    cout << "P2 : " << P2; 
    cout << P1 + P2;
    return 0;
}