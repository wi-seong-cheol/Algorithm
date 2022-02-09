//
//  main.cpp
//  15683
//
//  Created by wi_seong on 2022/02/08.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int board1[10][10];
int board2[10][10];
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<pair<int, int>> cctv;

void upd(int x, int y, int dir) {
    dir %= 4;
    while(1) {
        x += dx[dir];
        y += dy[dir];
        if(board2[x][y] == 6 || x < 0 || x >= n || y < 0 || y >= m) {
            return;
        }
        if(board2[x][y] != 0) continue;
        board2[x][y] = 7;
    }
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    cin >> n >> m;
    int mn = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board1[i][j];
            if(board1[i][j] != 0 && board1[i][j] != 6)
                cctv.push_back({i, j});
            if(board1[i][j] == 0) mn++;
        }
    }
    
    for(int tmp = 0; tmp < (1 << (2*cctv.size())); tmp++) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                board2[i][j] = board1[i][j];
        int brute = tmp;
        for(int i = 0; i < cctv.size(); i++) {
            int dir = brute % 4;
            brute /= 4;
            int x = cctv[i].X;
            int y = cctv[i].Y;
            switch (board1[x][y]) {
                case 1:
                    upd(x,y,dir);
                    break;
                case 2:
                    upd(x,y,dir);
                    upd(x,y,dir+2);
                    break;
                case 3:
                    upd(x,y,dir);
                    upd(x,y,dir+1);
                    break;
                case 4:
                    upd(x,y,dir);
                    upd(x,y,dir+1);
                    upd(x,y,dir+2);
                    break;
                case 5:
                    upd(x,y,dir);
                    upd(x,y,dir+1);
                    upd(x,y,dir+2);
                    upd(x,y,dir+3);
                    break;
                default:
                    break;
            }
        }
        int val = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                val += (board2[i][j] == 0);
        mn = min(mn, val);
    }
    cout << mn;
    
    return 0;
}
