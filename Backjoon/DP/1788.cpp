//
//  1788.cpp
//  main
//
//  Created by wi_seong on 2022/03/10.
//

#include <iostream>
#include <algorithm>

using namespace std;
const int mod = 1e9;
int n;
int d[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    d[0] = 0; d[1] = 1;
    if(n >= 0) {
        for(int i = 2; i <= n; i++) {
            d[i] = (d[i - 1] + d[i - 2]) % mod;
        }
    } else {
        n = abs(n);
        for(int i = 2; i <= n; i++) {
            d[i] = (d[i - 2] - d[i - 1]) % mod;
        }
    }
    if(d[n] == 0) cout << 0 << '\n';
    else if(d[n] < 0) cout << -1 << '\n';
    else cout << 1 << '\n';
    cout << abs(d[n]);
    
    return 0;
}
