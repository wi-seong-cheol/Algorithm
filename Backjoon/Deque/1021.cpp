//
//  1021.cpp
//  main
//
//  Created by wi_seong on 2022/02/22.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    deque<int> dq;
    for(int i = 1; i <= n; i++) dq.push_back(i);
    int ans = 0;
    while(m--) {
        int a; cin >> a;
        auto idx = find(dq.begin(), dq.end(), a) - dq.begin();
        while(a != dq.front()) {
            if(idx < dq.size() - idx) {
                dq.push_back(dq.front());
                dq.pop_front();
            } else {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            ans++;
        }
        dq.pop_front();
    }
    cout << ans;
    
    return 0;
}
