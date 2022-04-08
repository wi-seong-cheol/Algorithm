//
//  1493.cpp
//  main
//
//  Created by wi_seong on 2022/04/08.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define ll long long
int l, w, h, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> w >> h;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    ll ans = 0;
    ll before = 0;
    for(int i = n - 1; i >= 0; i--) {
        before <<= 3;
        ll pc = (ll)(l >> i) * (w >> i) * (h >> i) - before;
        ll nc = min((ll)v[i].second, pc);

        before += nc;
        ans += nc;
    }
    
    if(before == (ll) l * w * h) cout << ans;
    else cout << -1;
    
    return 0;
}
