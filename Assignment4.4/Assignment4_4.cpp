#include "Polynomial.h"
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main () {
    Polynomial P1(4);
    cin >> P1;
    cout << P1;
    cout << P1(2);
    return 0;
}