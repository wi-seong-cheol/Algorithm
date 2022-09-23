//
//  1916.cpp
//  main
//
//  Created by wi_seong on 2022/09/22.
//

/*
 [Input]
 5
 8
 1 2 2
 1 3 3
 1 4 1
 1 5 10
 2 4 2
 3 4 1
 3 5 1
 4 5 3
 1 5
 
 [Output]
 4
 */
// 시간복잡도 : O(ElgE)
// 최악 시간: 100000lg(100000) = 500000
// 단, 다익스트라 알고리즘은 음수인 간선에서는 사용할 수 없음

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
#define X first
#define Y second

int v, e, st, en;
const int INF = 1e9 + 10;
vector<pair<int, int>> adj[1001];
int d[1001];    // 최단 거리 테이블

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> v >> e;
    fill(d, d+v+1, INF);
    while(e--) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    
    cin >> st >> en;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[st] = 0;
    pq.push({d[st], st});
    
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y] != cur.X) continue;
        for(auto nxt: adj[cur.Y]) {
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }
    cout << d[en];
    return 0;
}

