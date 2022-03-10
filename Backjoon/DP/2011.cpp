//
//  2011.cpp
//  main
//
//  Created by wi_seong on 2022/03/10.
//

#include <iostream>
#include <string>

using namespace std;
const int mod = 1000000;
int a[5001];
int d[5001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s; cin >> s;
    int size = int(s.size());
    for(int i = 1; i <= size; i++) a[i] = s[i - 1] - '0';
    d[0] = 1;
    for(int i = 1; i <= size; i++) {
        if(a[i] > 0) d[i] = (d[i] + d[i - 1]) % mod;
        int x = a[i - 1] * 10 + a[i];
        if(x >= 10 && x <= 26) d[i] = (d[i] + d[i - 2]) % mod;
    }
    cout << d[size];
    
    return 0;
}

