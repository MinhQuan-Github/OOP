#include "Matrix.h"
#include <iostream>

using namespace std;

void solve(){
    int n; cin >> n;
    int N[n][n];
    for (int p = 0 ; p < n ; p ++)
        for (int q = 0 ; q <n ; q++)
            cin >> N[p][q];
    int i , j , k;
    double det = 1.0 , t;
    for ( i = 0 ; i < n - 1 ; i++){
        //t = N[i][i] / N[i+1][i];
        for (j = i + 1 ; j < n ; j++){
            if (N[j][i] == 0) continue;
            t = N[i][i] / N[j][i];
            if (N[j][i] != 0){
                for (k = i ; k < n ; k++){
                    N[j][k] = N[j][k] * t - N[i][k];
                }
            }
        }
    }
    cout << endl;
    for (int p = 0 ; p < n ; p ++){
        for (int q = 0 ; q <n ; q++){
            cout << N[p][q] << " ";
        }
        cout << endl;
    }
}

int main () {
    // Matrix M1(3);
    // cin >> M1;
    // cout << M1;
    // //cout << M1(2,4);
    // cout << (int)M1;
    solve();
    // Matrix M2(4);
    // cin >> M2;
    // cout << M2;
    // Matrix M = M1 * M2;
    // cout << M;
    // cout << M1 + M2;
    // cout << M1 - M2;
    return 0;
}