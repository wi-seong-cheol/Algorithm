//
//  7569.cpp
//  main
//
//  Created by wi_seong on 2022/02/25.
//

#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
int n, m, h;
int board[101][101][101];
int dist[101][101][101];
int dx[] = {0,0,0,0,1,-1};
int dy[] = {0,1,0,-1,0,0};
int dz[] = {1,0,-1,0,0,0};

bool OOB(int a, int b, int c) {return a<0 || a>=h || b<0 || b>=n || c<0 || c>=m;}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n >> h;
    int cnt1 = m * n * h;
    int cnt2 = 0;
    queue<tuple<int, int, int>> Q;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            fill(dist[i][j], dist[i][j]+m, -1);
            for(int k = 0; k < m; k++) {
                cin >> board[i][j][k];
                if(board[i][j][k] == -1) {
                    cnt1--;
                } else if (board[i][j][k] == 1) {
                    cnt2++;
                    dist[i][j][k] = 0;
                    Q.push({i,j,k});
                }
            }
        }
    }
    int res = 0;
    if(cnt1 == cnt2) {
        cout << res;
        return 0;
    }
    while(!Q.empty()) {
        int x, y, z;
        tie(x, y, z) = Q.front(); Q.pop();
        
        for(int dir = 0; dir < 6; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            if(OOB(nx, ny, nz) || dist[nx][ny][nz] != -1 || board[nx][ny][nz] == -1) continue;
            cnt2++;
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            if(cnt1 == cnt2) {
                cout << dist[nx][ny][nz];
                return 0;
            }
            Q.push({nx, ny, nz});
        }
    }
    cout << -1;
    return 0;
}
