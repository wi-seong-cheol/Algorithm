//
//  main.cpp
//  11051
//
//  Created by wi_seong on 2022/02/15.
//

#include <iostream>

using namespace std;
int n, k;
int d[1002][1002];
int mod = 10007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 1; i <= 1000; i++) {
        d[i][0] = d[i][i] = 1;
        for(int j = 1; j < i; j++) {
            d[i][j] = (d[i - 1][j] + d[i - 1][j - 1]) % mod;
        }
    }
    cin >> n >> k;
    cout << d[n][k];    
    
    return 0;
}
