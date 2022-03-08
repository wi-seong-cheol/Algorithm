//
//  1520.cpp
//  main
//
//  Created by wi_seong on 2022/03/08.
//

#include <iostream>

using namespace std;
int n, m;
int board[501][501];
int d[501][501];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool OOB(int a, int b) {return a < 0 || a >= n || b < 0 || b >= m;}
int func(int x, int y) {
    if(d[x][y] != -1) return d[x][y];
    if(x == n - 1 && y == m - 1) return 1;
    int &ret = d[x][y];
    ret = 0;
    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(OOB(nx, ny)) continue;
        if(board[nx][ny] < board[x][y]) ret += func(nx, ny);
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        fill(d[i], d[i] + m, -1);
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    }
    cout << func(0, 0);
    
    return 0;
}
