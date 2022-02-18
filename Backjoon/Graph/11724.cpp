//
//  11724.cpp
//  main
//
//  Created by wi_seong on 2022/02/18.
//

#include <iostream>
#include <queue>

using namespace std;
vector<int> adj[1001];
bool vis[1001];

void bfs(int a) {
    queue<int> q;
    q.push(a);
    vis[a] = true;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto nxt : adj[cur]) {
            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int v, u; cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            bfs(i);
            ans++;
        }
    }
    cout << ans;
    return 0;
}
