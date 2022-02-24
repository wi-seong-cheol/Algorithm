//
//  3197.cpp
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
const int MX = 1520;
int r, c;
int x, y;
string board[MX];
bool vis[MX][MX];
int visited[MX][MX];
bool isPossible = false;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
queue <pair<int, int>> Q;
queue <pair<int, int>> Q2;
queue <pair<int, int>> LQ;
queue <pair<int, int>> LQ2;

bool OOB(int a, int b) {return a < 0 || a >= r || b < 0 || b >= c;}

void melting() {
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        visited[cur.X][cur.Y] = 1;
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || visited[nx][ny]) continue;
            if(board[nx][ny] == 'X') Q2.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }
}

bool search() {
    while(!LQ.empty()) {
        auto cur = LQ.front(); LQ.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny]) continue;
            if(board[nx][ny] == 'X'){
                vis[nx][ny] = 1;
                LQ2.push({nx, ny});
                continue;
            }
            else if(board[nx][ny] == 'L'){
                isPossible = true;
                break;
            }
            vis[nx][ny] = 1;
            LQ.push({nx, ny});
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        cin >> board[i];
        for(int j = 0; j < c; j++) {
            if(board[i][j] == 'L') {
                x = i;
                y = j;
            }
            if(board[i][j] != 'X') Q.push({i, j});
        }
    }
    
    LQ.push({x, y});
    board[x][y] = '.';
    vis[x][y] = 1;
    int day = 0;
    while(!isPossible) {
        melting();
        while(!Q2.empty()) {
            auto cur = Q2.front(); Q2.pop();
            board[cur.X][cur.Y] = '.';
            Q.push({cur.X, cur.Y});
        }
        day++;
        search();
        while(!LQ2.empty()) {
            auto cur = LQ2.front(); LQ2.pop();
            LQ.push({cur.X, cur.Y});
        }
    }
    cout << day;
    return 0;
}
