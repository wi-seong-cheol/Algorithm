//
//  2667.cpp
//  main
//
//  Created by wi_seong on 2022/02/24.
//

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int n;
string board[26];
int vis[26][26];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool OOB(int a, int b) {return a < 0 || a >= n || b < 0 || b >= n;}

int bfs(int i, int j) {
    int ret = 0;
    queue<pair<int, int>> Q;
    Q.push({i,j});
    vis[i][j] = 1;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        ret++;
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || board[nx][ny] == '0' || vis[nx][ny] == 1) continue;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }
    return ret;
}

void solve() {
    vector<int> h;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(vis[i][j] == 0 && board[i][j] == '1') {
                cnt++;
                h.push_back(bfs(i, j));
            }
        }
    }
    cout << cnt << '\n';
    sort(h.begin(), h.end());
    for(auto a : h)
        cout << a << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    solve();
    
    return 0;
}
