//
//  1260.cpp
//  main
//
//  Created by wi_seong on 2022/02/18.
//

#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
vector<int> adj[1001];
bool vis[1001];
int n, m, v;

// 비재귀
void dfs_1() {
    stack<int> s;
    s.push(v);
    while(!s.empty()) {
        auto cur = s.top(); s.pop();
        if(vis[cur]) continue;
        vis[cur] = true;
        cout << cur << ' ';
        for(int i = 0; i < adj[cur].size(); i++) {
            int nxt = adj[cur][adj[cur].size() - 1 - i];
            if(vis[nxt]) continue;
            s.push(nxt);
        }
    }
}

// 재귀
void dfs(int cur) {
    vis[cur] = true;
    cout << cur << ' ';
    for(auto nxt : adj[cur]) {
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}

void bfs() {
    queue<int> q;
    q.push(v);
    vis[v] = true;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        cout << cur << ' ';
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
    
    cin >> n >> m >> v;
    
    while(m--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());
    dfs(v);
    cout << '\n';
    fill(vis, vis+1001, false);
    bfs();
    
    return 0;
}
