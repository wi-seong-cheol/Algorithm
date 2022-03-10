//
//  1904.cpp
//  main
//
//  Created by wi_seong on 2022/03/10.
//

#include <iostream>

using namespace std;
const int mod = 15746;
int n;
int d[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    d[1] = 1; d[2] = 2;
    for(int i = 3; i <= n; i++)
        d[i] = (d[i - 1] + d[i - 2]) % mod;
    cout << d[n];
    
    return 0;
}
