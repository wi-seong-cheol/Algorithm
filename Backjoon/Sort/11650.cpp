//
//  11650.cpp
//  main
//
//  Created by wi_seong on 2022/03/04.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    pair<int, int> x[n];
    for(auto& s : x) cin >> s.first >> s.second;
    sort(x, x + n);
    for(auto s : x) cout << s.first << ' ' << s.second << '\n';
    
    return 0;
}
