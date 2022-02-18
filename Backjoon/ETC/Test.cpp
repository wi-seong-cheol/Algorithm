//
//  main.cpp
//  Test
//
//  Created by wi_seong on 2022/01/11.
//

#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second

void prim() {
    int v, e;

    vector<pair<int, int>> adj[10005];
    bool chk[10005];
    int cnt = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    chk[1] = 1;
    for(auto nxt : adj[1])
        pq.push({nxt.X, 1, nxt.Y});
    while(cnt < v - 1) {
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if(chk[b]) continue;
        cout << cost << ' ' << a << ' ' << b << '\n';
        chk[b] = 1;
        cnt++;
        for(auto nxt : adj[b]) {
            if(!chk[nxt.Y])
                pq.push({nxt.X, b, nxt.Y});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    return 0;
}
