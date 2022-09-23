//
//  2749.cpp
//  main
//
//  Created by wi_seong on 2022/09/23.
//

#include <iostream>

using namespace std;
#define ll long long

const int mod = 1000000;
ll n;
ll d[1500001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    d[1] = 1;
    for(int i = 2; i <= 1500000; i++) {
        d[i] = (d[i - 1] + d[i - 2]) % mod;
    }
    cout << d[n % 1500000];
    
    return 0;
}
