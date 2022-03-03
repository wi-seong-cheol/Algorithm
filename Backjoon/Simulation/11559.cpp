//
//  11559.cpp
//  main
//
//  Created by wi_seong on 2022/03/03.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define X first
#define Y second
bool isPuyo;
bool vis[12][6];
string board[12];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int ans;

bool OOB(int a, int b) {return a < 0 || a >= 12 || b < 0 || b >= 6;}

void resetVis() {
    for(int i = 0; i < 12; i++)
        fill(vis[i], vis[i] + 6, false);
}

void puyo(int x, int y) {
    vis[x][y] = true;
    char color = board[x][y];
    queue<pair<int, int>> Q;
    vector<pair<int, int>> tmp;
    Q.push({x, y}); tmp.push_back({x, y});
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny] || board[nx][ny] == '.' || board[nx][ny] != color) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
            tmp.push_back({nx, ny});
        }
    }
    
    if(tmp.size() >= 4) {
        isPuyo = true;
        for(auto cur : tmp)
            board[cur.X][cur.Y] = '.';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < 12; i++)
        cin >> board[i];
    
    do {
        isPuyo = false;
        for(int i = 0; i < 6; ++i) {
            for(int j = 10; j >= 0; --j) {
                int tmp = j;
                while(tmp < 11 && board[tmp + 1][i] == '.'){
                    swap(board[tmp][i], board[tmp+1][i]);
                    ++tmp;
                }
            }
        }
        for(int i = 0; i < 12; ++i)
            for(int j = 0; j < 6; ++j)
                if(!vis[i][j]&&board[i][j]!='.')
                    puyo(i, j);
        if(isPuyo) ans++;
        resetVis();
    } while(isPuyo);
    
    cout << ans;
    
    return 0;
}
