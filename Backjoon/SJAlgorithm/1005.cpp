//
//  main.cpp
//  1005
//
//  Created by wi_seong on 2022/01/05.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    
    int tc; cin >> tc;
    int ind[1001], t[1001], dist[1001];
    vector<int> G[1001];
    
    for(int i = 0; i < tc; i++) {
        int N, K; cin >> N >> K;
        memset(G, 0, sizeof(G));
        memset(dist, 0, sizeof(dist));
        memset(ind, 0, sizeof(ind));
        
        for(int j = 1; j <= N; j++) {
            cin >> t[j];
        }
        
        for(int j = 0; j < K; j++) {
            int u, v; cin >> u >> v;
            G[u].push_back(v);
            ind[v]++;
        }
        int W; cin >> W;
        queue<int> q;
        for (int i = 1; i <= N; i++) {
            if (!ind[i]) { q.push(i); dist[i] = t[i]; }
        }
        while (!q.empty()) {
            int x = q.front(); q.pop();
            if (x == W) break;
            
            for (int nx : G[x]) {
                if (--ind[nx] == 0) {
                    q.push(nx);
                }
                if (dist[nx] < dist[x] + t[nx]) {
                    dist[nx] = dist[x] + t[nx];
                }
            }
        }
        cout << dist[W] << '\n';
    }
    
    return 0;
}
