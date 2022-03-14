//
//  2482.cpp
//  main
//
//  Created by wi_seong on 2022/03/13.
//

#include <iostream>

using namespace std;
const int mod = 1e9 + 3;
int n, k;
int d[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 1; i <= n; i++) d[i][1] = i;
    for(int i = 4; i <= n; i++) {
        for(int j = 2; j <= k; j++) {
            if(j > i / 2) break;
            d[i][j] = (d[i - 1][j] + d[i - 2][j - 1]) % mod;
        }
    }
    cout << d[n][k];
    
    return 0;
}
