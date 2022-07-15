//
//  1493.cpp
//  main
//
//  Created by wi_seong on 2022/10/07.
//

/*
 [Input]
 4 4 8
 3
 0 10
 1 10
 2 1
 [Output]
 9
 */
// 시간복잡도: O(n)
// 최악시간: 20

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
#define ll long long
int l, w, h, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> l >> w >> h >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    ll ans = 0;
    ll before = 0;
    for(int i = n - 1; i >= 0; i--) {
        before <<= 3;
        ll pc = (ll)(l >> i) * (ll)(w >> i) * (ll)(h >> i) - before;
        ll nc = min((ll)v[i].second, pc);
        
        before += nc;
        ans += nc;
    }
    if(before == (ll) l * w * h) cout << ans;
    else cout << -1;
    
    return 0;
}
