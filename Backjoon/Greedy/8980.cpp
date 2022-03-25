//
//  8980.cpp
//  main
//
//  Created by wi_seong on 2022/03/25.
//

#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, c, s, e, w;
int ans;
int truck[2001];
vector<tuple<int, int , int>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> c;
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> s >> e >> w;
        v.push_back({e, s, w});
    }
    sort(v.begin(), v.end());
    for(auto d : v) {
        tie(e, s, w) = d;
        bool loadable = true;
        for(int i = s; i < e; i++) {
            w = min(w, c - truck[i]);
            if(!w) {
                loadable = false;
                break;
            }
        }
        if(loadable) {
            ans += w;
            for(int i = s; i < e; i++) truck[i] += w;
        }
    }
    cout << ans;
    
    return 0;
}
