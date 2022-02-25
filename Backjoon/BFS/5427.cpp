//
//  5427.cpp
//  main
//
//  Created by wi_seong on 2022/02/25.
//

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
#define X first
#define Y second
const int SIZE = 1000;
int t, w, h;
int x, y;
string board[SIZE+1];
int firedist[SIZE+1][SIZE+1];
int sangdist[SIZE+1][SIZE+1];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool OOB(int a, int b) {return a < 0 || a >= h || b < 0 || b >= w;}

void initvis() {
    for(int i = 0; i < h; i++) {
        fill(firedist[i], firedist[i]+w, 0);
        fill(sangdist[i], sangdist[i]+w, 0);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        queue<pair<int, int>> Q;
        queue<pair<int, int>> F;
        bool escape = false;
        initvis();
        cin >> w >> h;
        for(int i = 0; i < h; i++) {
            cin >> board[i];
            for(int j = 0; j < w; j++) {
                if(board[i][j] == '@') {
                    Q.push({i,j});
                    sangdist[i][j] = 1;
                } else if(board[i][j] == '*') {
                    F.push({i,j});
                    firedist[i][j] = 1;
                }
            }
        }
        while(!F.empty()) {
            auto cur = F.front(); F.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(OOB(nx, ny) || firedist[nx][ny] || board[nx][ny] == '#') continue;
                firedist[nx][ny] = firedist[cur.X][cur.Y] + 1;
                F.push({nx,ny});
            }
        }
        while((!Q.empty()) && (!escape)) {
            auto cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(OOB(nx, ny)) {
                    cout << sangdist[cur.X][cur.Y] << '\n';
                    escape = true;
                    break;
                }
                if(sangdist[nx][ny] || board[nx][ny] == '#') continue;
                if(firedist[nx][ny] != 0 && firedist[nx][ny] <= sangdist[cur.X][cur.Y] + 1) continue;
                sangdist[nx][ny] = sangdist[cur.X][cur.Y] + 1;
                Q.push({nx,ny});
            }
        }
        if(!escape) cout << "IMPOSSIBLE" << '\n';
    }
    
    return 0;
}
