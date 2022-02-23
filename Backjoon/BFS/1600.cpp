//
//  1600.cpp
//  main
//
//  Created by wi_seong on 2022/02/23.
//

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
#define X first
#define Y second
int n, m, k;
int board[202][202];
int dist[202][202][32];
int dx[12] = {0,1,0,-1,1,2,2,1,-1,-2,-2,-1};
int dy[12] = {1,0,-1,0,2,1,-1,-2,-2,-1,1,2};

void bfs() {
    queue<tuple<int,int,int>> Q;
    dist[0][0][0] = 0;
    Q.push({0,0,0});
    while(!Q.empty()) {
        auto [x,y,z] = Q.front(); Q.pop();
        if(x == n - 1 && y == m - 1) {
            cout << dist[x][y][z] << '\n';
            return;
        }
        for(int dir = 0; dir < 12; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == 1) continue;
            int nz = z;
            if(dir >= 4) nz++;
            if(dist[nx][ny][nz] != -1 || nz > k) continue;
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            Q.push({nx,ny,nz});
        }
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k >> m >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            fill(dist[i][j], dist[i][j]+32, -1);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    bfs();
    
    return 0;
}
