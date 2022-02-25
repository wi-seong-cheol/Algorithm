//
//  6593.cpp
//  main
//
//  Created by wi_seong on 2022/02/25.
//

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <tuple>

using namespace std;
int L, R, C;
int sx, sy, sz;
int ex, ey, ez;
string board[31][31];
int dist[31][31][31];
int dx[] = {0,0,0,0,1,-1};
int dy[] = {0,1,0,-1,0,0};
int dz[] = {1,0,-1,0,0,0};

bool OOB(int a, int b, int c) {return a < 0 || a >= L || b < 0 || b >= R || c < 0 || c >= C;}

void initdist() {
    for(int i = 0; i < L; i++)
        for(int j = 0; j < R; j++)
            fill(dist[i][j], dist[i][j]+C, -1);
}

void solve() {
    queue<tuple<int, int, int>> Q;
    Q.push({sx, sy, sz});
    dist[sx][sy][sz] = 0;
    while(!Q.empty()) {
        int x, y, z;
        tie(x, y, z) = Q.front(); Q.pop();
        if(x == ex && y == ey && z == ez) {
            cout << "Escaped in " << dist[x][y][z] << " minute(s)." << '\n';
            return;
        }
        for(int dir = 0; dir < 6; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            if(OOB(nx, ny, nz) || dist[nx][ny][nz] != -1 || board[nx][ny][nz] == '#') continue;
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            Q.push({nx, ny, nz});
        }
    }
    cout << "Trapped!" << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        cin >> L >> R >> C;
        if(L == 0 && R == 0 && C == 0) break;
        for(int i = 0; i < L; i++) {
            for(int j = 0; j < R; j++) {
                cin >> board[i][j];
                for(int k = 0; k < C; k++) {
                    if(board[i][j][k] == 'S') {
                        sx = i;
                        sy = j;
                        sz = k;
                    } else if (board[i][j][k] == 'E') {
                        ex = i;
                        ey = j;
                        ez = k;
                    }
                }
            }
        }
        initdist();
        solve();
    }
    
    return 0;
}
