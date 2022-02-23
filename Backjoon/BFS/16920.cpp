//
//  16920.cpp
//  main
//
//  Created by wi_seong on 2022/02/23.
//

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
int n, m, p;
queue<tuple<int, int, int>> Q[10];
int canExtend[1001][1001];
int area[10];
int mov[10];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void bfs() {
    while(1) {
        bool isExtend = 0;
        for(int i = 1; i <= p; i++) {
            queue<tuple<int,int,int>> nxtQ;
            while(!Q[i].empty()) {
                int curx, cury, curstep;
                tie(curx, cury, curstep) = Q[i].front(); Q[i].pop();
                if(curstep >= mov[i]) {
                    nxtQ.push({curx, cury, 0});
                    continue;
                }
                for(int dir = 0; dir < 4; dir++) {
                    int x = curx + dx[dir];
                    int y = cury + dy[dir];
                    if(x < 0 || x >= n || y < 0 || y >= m) continue;
                    if(!canExtend[x][y]) continue;
                    Q[i].push({x,y,curstep+1});
                    canExtend[x][y] = 0;
                    area[i]++;
                    isExtend = 1;
                }
            }
            Q[i] = nxtQ;
        }
        if(!isExtend) break;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> p;
    for(int i = 1; i <= p; i++)
        cin >> mov[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c; cin >> c;
            if(c == '.') canExtend[i][j] = 1;
            else if(c == '#') canExtend[i][j] = 0;
            else {
                canExtend[i][j] = 0;
                Q[c - '0'].push({i,j,0});
                area[c - '0']++;
            }
        }
    }
    bfs();
    for(int i = 1; i <= p; i++)
        cout << area[i] << ' ';
    return 0;
}
