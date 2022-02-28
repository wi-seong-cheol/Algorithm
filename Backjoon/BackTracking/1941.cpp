//
//  1941.cpp
//  main
//
//  Created by wi_seong on 2022/03/02.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
char board[5][5];
bool mask[25];
int ans;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool OOB(int a, int b) {return a < 0 || a >= 5 || b < 0 || b >= 5;}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            cin >> board[i][j];
    fill(mask + 7, mask + 25, true);
    do {
        queue<pair<int, int>> Q;
        int dasom = 0, adj = 0;
        bool isp7[5][5] = {}, vis[5][5] = {};
        for(int i = 0; i < 25; i++) {
            if(!mask[i]) {
                int x = i /5, y = i % 5;
                isp7[x][y] = true;
                if(Q.empty()) {
                    Q.push({x, y});
                    vis[x][y] = true;
                }
            }
        }
        while(!Q.empty()) {
            int x, y;
            tie(x, y) = Q.front(); Q.pop();
            adj++;
            dasom += board[x][y] == 'S';
            for(int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(OOB(nx, ny) || vis[nx][ny] || !isp7[nx][ny]) continue;
                vis[nx][ny] = true;
                Q.push({nx, ny});
            }
        }
        ans += (adj >= 7 && dasom >= 4);
    } while (next_permutation(mask, mask + 25));
    cout << ans;
    return 0;
}
