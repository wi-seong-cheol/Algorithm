//
//  2170_1.cpp
//  main
//
//  Created by wi_seong on 2022/03/24.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<pair<int, int>> lines;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        lines.push_back({x, y});
    }
    sort(lines.begin(), lines.end());
    int l, r;
    tie(l, r) = lines[0];
    int ans = 0;
    for(int i = 1; i < n; i++) {
        int a, b;
        tie(a, b) = lines[i];
        if(a <= r && b >= r) r = b;
        else if(a > r) {
            ans += r - l;
            l = a;
            r = b;
        }
    }
    cout << ans + r - l;
    
    return 0;
}
