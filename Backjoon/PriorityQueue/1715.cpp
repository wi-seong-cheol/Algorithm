//
//  1715.cpp
//  main
//
//  Created by wi_seong on 2022/02/18.
//

#include <iostream>
#include <queue>

using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--) {
        int val; cin >> val;
        pq.push(val);
    }
    int ans = 0;
    while(pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        ans += a + b;
        pq.push(a+b);
    }
    cout << ans;
    return 0;
}
