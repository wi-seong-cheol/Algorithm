//
//  9328.cpp
//  main
//
//  Created by wi_seong on 2022/02/25.
//

#include <iostream>
#include <queue>
#include <string>

using namespace std;
#define X first
#define Y second
const int MX = 120;
int h, w;
string keystr;
char board[MX][MX];
bool vis[MX][MX];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool OOB(int a, int b) {return a < 0 || a > h + 1 || b < 0 || b > w + 1;}
void init() {
    for(int i = 0; i <= h+1; i++) {
        fill(vis[i], vis[i]+w+2, 0);
        fill(board[i], board[i]+w+2, 0);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int res = 0;
        int key[26] = {};
        queue<pair<int, int>> Q;
        queue<pair<int, int>> door[26];
        cin >> h >> w;
        init();
        for(int i  = 1; i <= h; i++)
            for(int j = 1; j <= w; j++) cin >> board[i][j];
        cin >> keystr;
        for(auto k : keystr) key[k - 'a'] = 1;
        Q.push({0, 0});
        vis[0][0] = 1;
        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(OOB(nx, ny) || vis[nx][ny] == 1 || board[nx][ny] == '*') continue;
                vis[nx][ny] = 1;
                if (board[nx][ny] >= 'a' && board[nx][ny] <= 'z') {
                    int k = board[nx][ny] - 'a';
                    key[k] = 1;
                    while(!door[k].empty()) {
                        auto ndoor = door[k].front(); door[k].pop();
                        Q.push({ndoor.X, ndoor.Y});
                    }
                } else if (board[nx][ny] >= 'A' && board[nx][ny] <= 'Z') {
                    int k = board[nx][ny] + 32 - 'a';
                    if(!key[k]) {
                        door[k].push({nx, ny});
                        continue;
                    }
                } else if (board[nx][ny] == '$') res++;
                Q.push({nx, ny});
            }
        }
        cout << res << '\n';
    }
    
    return 0;
}
