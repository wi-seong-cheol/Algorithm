//
//  11651.cpp
//  main
//
//  Created by wi_seong on 2022/03/04.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    pair<int, int> x[n];
    for(auto& s : x) cin >> s.second >> s.first;
    sort(x, x + n);
    for(auto s : x) cout << s.second << ' ' << s.first << '\n';
    return 0;
}
