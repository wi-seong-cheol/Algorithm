//
//  14442.cpp
//  main
//
//  Created by wi_seong on 2022/02/23.
//

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
int n, m, k;
string board[1002];
int dist[1002][1002][12];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void bfs() {
    queue<tuple<int, int, int>> Q;
    dist[0][0][0] = 1;
    Q.push({0,0,0});
    while(!Q.empty()) {
        auto [x, y, w] = Q.front(); Q.pop();
        if(x == n - 1 && y == m - 1) {
            cout << dist[x][y][w];
            return;
        }
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int nw = w;
            if(board[nx][ny] == '1') nw++;
            if(dist[nx][ny][nw] > 0 || nw > k) continue;
            dist[nx][ny][nw] = dist[x][y][w] + 1;
            Q.push({nx, ny, nw});
        }
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    bfs();
    
    return 0;
}
