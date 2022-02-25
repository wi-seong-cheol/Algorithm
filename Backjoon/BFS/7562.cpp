//
//  7562.cpp
//  main
//
//  Created by wi_seong on 2022/02/25.
//

#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second
const int MX = 300;
int n;
int dist[MX+1][MX+1];
int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};

bool OOB(int a, int b) {return a < 0 || a >= n || b < 0 || b >= n;}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int x1, y1, x2, y2;
        queue<pair<int, int>> Q;
        cin >> n;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = 0; i < n; i++)
            fill(dist[i], dist[i]+n+1, -1);
        Q.push({x1, y1});
        dist[x1][y1] = 0;
        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            if(cur.X == x2 && cur.Y == y2) break;
            for(int dir = 0; dir < 8; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(OOB(nx, ny)|| dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
        cout << dist[x2][y2] << '\n';
    }
    
    return 0;
}
