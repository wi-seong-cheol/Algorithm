//
//  1197.cpp
//  main
//
//  Created by wi_seong on 2022/02/18.
//

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
#define X first
#define Y second
int v, e;
vector<pair<int, int>> adj[10005];
bool chk[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
        adj[b].push_back({cost, a});
    }
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    int cnt = 0;
    int ans = 0;
    chk[1] = 1;
    for(auto nxt : adj[1])
        pq.push({nxt.X, 1, nxt.Y});
    while(cnt < v - 1) {
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if(chk[b]) continue;
        ans += cost;
        chk[b] = 1;
        cnt++;
        for(auto nxt : adj[b]) {
            if(!chk[nxt.Y])
                pq.push({nxt.X, 1, nxt.Y});
        }
    }
    cout << ans;
    return 0;
}
