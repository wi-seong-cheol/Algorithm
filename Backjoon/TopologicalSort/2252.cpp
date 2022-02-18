//
//  2252.cpp
//  main
//
//  Created by wi_seong on 2022/02/18.
//

#include <iostream>
#include <queue>

using namespace std;
int n, m;
vector<int> adj[32001];
int deg[32001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(deg[i] == 0) q.push(i);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for(auto nxt : adj[cur]) {
            deg[nxt]--;
            if(deg[nxt] == 0) q.push(nxt);
        }
    }
    
    return 0;
}
