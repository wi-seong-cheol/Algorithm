//
//  main.cpp
//  6064
//
//  Created by wi_seong on 2022/02/15.
//

#include <iostream>

using namespace std;
int m, n, x, y;

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

int lcm(int m, int n) {
    return m / gcd(m, n) * n;
}

int solve() {
    if(x == m) x = 0;
    if(y == n) y = 0;
    int l = lcm(m, n);
    for(int i = x; i <= l; i+=m) {
        if(i == 0) continue;
        if(i % n == y)
            return i;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> m >> n >> x >> y;
        cout << solve() << '\n';
    }
    
    return 0;
}
