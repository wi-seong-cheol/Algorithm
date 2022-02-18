//
//  main.cpp
//  Test
//
//  Created by wi_seong on 2022/01/11.
//

#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10];
int p[10];

void bfs(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for(int nxt : adj[cur]) {
            if(p[cur] == nxt) continue;
            q.push(nxt);
            p[nxt] = cur;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}
