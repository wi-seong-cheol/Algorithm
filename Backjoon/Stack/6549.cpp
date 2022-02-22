//
//  6549.cpp
//  main
//
//  Created by wi_seong on 2022/02/22.
//

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;
#define X first
#define Y second
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        int n; cin >> n;
        if(n == 0) break;
        ll res = 0;
        stack<pair<int, int>> s;
        for(int i = 0; i < n; i++) {
            int h; cin >> h;
            int idx = i;
            
            while(!s.empty() && s.top().X >= h) {
                res = max(res, 1LL * (i - s.top().Y) * s.top().X);
                idx = s.top().Y;
                s.pop();
            }
            s.push({h, idx});
        }
        while(!s.empty()) {
            res = max(res, 1LL * (n - s.top().Y) * s.top().X);
            s.pop();
        }
        cout << res << '\n';
    }
    return 0;
}
