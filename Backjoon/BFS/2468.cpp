//
//  2468.cpp
//  main
//
//  Created by wi_seong on 2022/02/24.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int n;
int board[101][101];
int vis[101][101];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int mx;

bool OOB(int a, int b) {return a < 0 || a >= n || b < 0 || b >= n;}

void bfs(int i, int j, int h) {
    queue<pair<int, int>> Q;
    vis[i][j] = 1;
    Q.push({i,j});
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || board[nx][ny] <= h || vis[nx][ny] != -1) continue;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }
}

void reset_vis() {
    for(int i = 0; i < n; i++)
        fill(vis[i],vis[i]+n,-1);
}

int solve() {
    int ret = 1;
    for(int  h = 1; h <= mx; h++) {
        reset_vis();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(vis[i][j] == -1 && board[i][j] > h) {
                    cnt++;
                    bfs(i, j, h);
                }
            }
        }
        ret = max(ret, cnt);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            mx = max(mx, board[i][j]);
        }
    }
    cout << solve();
    
    return 0;
}
