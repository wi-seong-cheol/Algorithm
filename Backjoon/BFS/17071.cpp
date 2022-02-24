//
//  17071.cpp
//  main
//
//  Created by wi_seong on 2022/02/24.
//

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
const int LMT = 500'000;
int n, k;
int dist[LMT + 2];
int vis[2][LMT + 2];

void bfs() {
    queue<pair<int, int>> Q;
    Q.push({n,0});
    vis[0][n] = 0;
    while(!Q.empty()) {
        int v, vt, nvt;
        tie(v, vt) = Q.front(); Q.pop();
        nvt = vt + 1;
        for(int nv : {v-1, v+1, v*2}) {
            if(nv < 0 || nv > LMT || vis[nvt % 2][nv] != -1) continue;
            vis[nvt % 2][nv] = nvt;
            Q.push({nv, nvt});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int ans = 0;
    cin >> n >> k;
    for(int i = 0 ; i < 2; i++)
        fill(vis[i], vis[i]+LMT+2, -1);
    bfs();
    
    bool found = false;
    while (k <= LMT) {
      if (vis[ans % 2][k] <= ans) {
        found = true;
        break;
      }
      k += ++ans;
    }
    if (found) cout << ans;
    else cout << -1;
    return 0;
}
