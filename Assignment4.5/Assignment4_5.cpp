#include "SetOfInteger.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main (){
    // int data[] = {0,1,2,3,4,5,6,7,8,9};
    // int i = 0; bool check = false; int x = 0;
    // for (int k = 0 ; k < 10 ; k++){
    //     if (data[k] == x) {
    //         check = true;
    //         i = k;
    //         break;
    //     }
    // }
    // cout << i;
    // int *temp = new int [9];
    // if (check == false) {
    //     delete [] temp;
    // } else {
    //     for (int j = 0 ; j < 9 ; j++){
    //         if (j < i) temp[j] = data[j];
    //         else temp[j] = data[j+1];
    //     }
    //     for (int k = 0 ; k < 9 ; k++) cout << temp[k] << " " ;
    // }
    
    SetOfInteger S1;
    S1 = S1 + 1 + 2 + 3 + 3 + 4 + 5;
    cout << "S1 : " << S1;
    SetOfInteger S2 ;
    S2 = S2 + 2 + 2 + 3 + 5 + 5 + 0;
    cout << "S2 : " << S2;

    cout << "\nS1 + S2 : " << S1 + S2;
    cout << "S1 : " << S1;
    cout << "S2 : " << S2;
    cout << "\nS1 - S2 : " << S1 - S2;
    cout << "S1 : " << S1;
    cout << "S2 : " << S2;
    cout << "\nS1 * S2 : " << S1 * S2;
    cout << "S1 : " << S1;
    cout << "S2 : " << S2;
    cout << "\nS1 - 3  : " << S1 - 3; 
    cout << "S1 + 6  : " << S1 + 6;
    S2 = S1;
    cout << "S2 : " << S2;
    cout << "S1[3] : " << S1[3] << endl;
    cout << "S1(1) : " << S1(1) << endl;
    cout << "S1(3) : " << S1(3) << endl;
    
    return 0;
}