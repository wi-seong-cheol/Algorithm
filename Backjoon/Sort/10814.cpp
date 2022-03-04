//
//  10814.cpp
//  main
//
//  Created by wi_seong on 2022/03/04.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    pair<int, string> x[n];
    for(auto& s: x) cin >> s.first >> s.second;
    stable_sort(x, x + n, [&](pair<int, string> a, pair<int, string> b) {
        return a.first < b.first;
    });
    for(auto p : x) cout << p.first << ' ' << p.second << '\n';
    
    return 0;
}
