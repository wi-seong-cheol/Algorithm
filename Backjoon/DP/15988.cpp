//
//  15988.cpp
//  main
//
//  Created by wi_seong on 2022/03/09.
//

#include <iostream>

using namespace std;
const int MX = 1000001;
const int mod = 1e9 + 9;
int n;
int d[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    d[1] = 1; d[2] = 2; d[3] = 4;
    for(int i = 4; i < MX; i++)
        for(int j = 1; j <= 3; j++)
            d[i] = (d[i] + d[i - j]) % mod;
            
    int t; cin >> t;
    while(t--) {
        cin >> n;
        cout << d[n] << '\n';
    }
    
    return 0;
}
