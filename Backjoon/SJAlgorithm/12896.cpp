//
//  main.cpp
//  12896
//
//  Created by wi_seong on 2022/01/03.
//

#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> g;
vector<bool> visited;
int m = -1, node = 0;
struct Node {
    int v;
    int cost;
};
void dfs(int x, int len) {
    if(m < len) {
        m = len;
        node = x;
    }
    visited[x] = true;
    for(int i = 0; i < g[x].size(); i++) {
        Node next{g[x][i], 1};
        if(!visited[next.v]) {
            dfs(next.v, len + next.cost);
            visited[x] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    g.resize(N);
    visited.resize(N);
    
    for(int i =0; i < N-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(0, 0);
    fill(visited.begin(),visited.end(),false);
    m = -1;
    dfs(node, 0);
    cout << (1+m)/2 << '\n';
    return 0;
}
