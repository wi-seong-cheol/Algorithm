//
//  2206.cpp
//  main
//
//  Created by wi_seong on 2022/02/24.
//

#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int n, m;
bool board[1000][1000];
int dist[1000][1000][2];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool OOB(int a, int b) { return a < 0 || a >= n || b < 0 || b >= m; }

int bfs() {
    queue<tuple<int, int, int>> Q;
    Q.push({0,0,0});
    dist[0][0][0] = dist[0][0][1] = 1;
    while(!Q.empty()) {
        auto [x,y,z] = Q.front(); Q.pop();
        if(x == n-1 && y == m-1) return dist[x][y][z];
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(OOB(nx, ny)) continue;
            int nz = z;
            if(board[nx][ny]) nz++;
            if(nz > 1 || dist[nx][ny][nz] != -1) continue;
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            Q.push({nx,ny,nz});
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            fill(dist[i][j], dist[i][j]+2, -1);
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < m; j++)
            if(s[j] == '1') board[i][j] = 1;
    }
    cout << bfs();
    
    return 0;
}
