//
//  1256.cpp
//  main
//
//  Created by wi_seong on 2022/03/27.
//

#include <iostream>
#include <algorithm>

using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
ll d[444][222];
int n, m;
ll k;

ll comb(int n, int r) {
    if (n == r || r == 0) return 1;
    ll &ret = d[n][r];
    if (ret != -1) return ret;
    ll val = comb(n - 1, r - 1);
    ll val2 = comb(n - 1, r);
    if (val + val2 > 1'000'000'000) return ret = INF;
    return ret = val + val2;
}

void go(int n, int m, ll rest) {
    if (ll c = comb(n + m - 1, n - 1); n > 0 && rest <= c) {
        cout << 'a';
        go(n - 1, m, rest);
    } else if (m > 0) {
        cout << 'z';
        go(n, m - 1, rest - c);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < 444; i++)
        fill(d[i], d[i] + 222, -1);
    cin >> n >> m >> k;
    if(comb(n + m, n) < k) {
        cout << -1;
        return 0;
    }
    go(n, m, k);
}
