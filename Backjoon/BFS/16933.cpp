//
//  16933.cpp
//  main
//
//  Created by wi_seong on 2022/02/23.
//

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
int n, m, k;
string board[1001];
int dist[1001][1001][11][2];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void bfs() {
    queue<tuple<int,int,int,int>> Q;
    Q.push({0,0,0,0});
    dist[0][0][0][0] = 1;
    while(!Q.empty()) {
        auto [x,y,z,t] = Q.front(); Q.pop();
        if(x == n-1 && y == m-1) {
            cout << dist[x][y][z][t];
            return;
        }
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int nz = z;
            int nt = 1 - t;
            if(board[nx][ny] == '1') nz++;
            if(dist[nx][ny][nz][nt] > 0 || nz > k) continue;
            if(nz != z && t != 0){
                if(dist[x][y][z][nt] > 0) continue;
                dist[x][y][z][nt] = dist[x][y][z][t] + 1;
                Q.push({x, y, z, nt});
            }
            else{
                dist[nx][ny][nz][nt] = dist[x][y][z][t] + 1;
                Q.push({nx, ny, nz, nt});
            }
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
