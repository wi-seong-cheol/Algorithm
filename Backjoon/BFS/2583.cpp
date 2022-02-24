//
//  2583.cpp
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
int board[101][101];
bool vis[101][101];
int n, m, k;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool OOB(int a, int b) {return a < 0 || a >= n || b < 0 || b >= m;}

int bfs(int i, int j) {
    queue<pair<int, int>> Q;
    Q.push({i, j});
    vis[i][j] = 1;
    int ret = 0;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        ret++;
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny] != 0 || board[nx][ny] != 0) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
    return ret;
}

void solve() {
    vector<int> size;
    int cnt = 0;
    for(int  i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && board[i][j] != 1) {
                size.push_back(bfs(i, j));
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    sort(size.begin(), size.end());
    for(auto n : size)
        cout << n << ' ';
}

void check(int x1, int y1, int x2, int y2) {
    for(int i = y1; i < y2; i++)
          for(int j = x1; j < x2; j++)
            board[i][j] = 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        check(x1, y1, x2, y2);
    }
    solve();
    
    return 0;
}
