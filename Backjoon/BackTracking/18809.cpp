//
//  18809.cpp
//  main
//
//  Created by wi_seong on 2022/02/28.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int n, m, g, r;
int board[52][52];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<pair<int, int>> cand;
unsigned long candsz;
const int EMPTY = 0;
const int GREEN = 1;
const int RED = 2;
const int FLOWER = 3;

int brute[10];
bool OOB(int a, int b) {return a < 0 || a >= n || b < 0 || b >= m;}
int solve() {
    int cnt = 0;
    pair<int, int> state[52][52];
    queue<pair<int, int>> Q;
    for(int i = 0; i < candsz; i++) {
        if(brute[i] == GREEN || brute[i] == RED) {
            state[cand[i].X][cand[i].Y] = {0, brute[i]};
            Q.push(cand[i]);
        }
    }
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int curtime = state[cur.X][cur.Y].X;
        int curcolor = state[cur.X][cur.Y].Y;
        if(state[cur.X][cur.Y].Y == FLOWER) continue;
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || board[nx][ny] == 0) continue;
            if(state[nx][ny].Y == EMPTY) {
                state[nx][ny] = {curtime + 1, curcolor};
                Q.push({nx, ny});
            } else if (state[nx][ny].Y == RED) {
                if(curcolor == GREEN && state[nx][ny].X == curtime + 1) {
                    cnt++;
                    state[nx][ny].Y = FLOWER;
                }
            } else if (state[nx][ny].Y == GREEN) {
                if(curcolor == RED && state[nx][ny].X == curtime + 1) {
                    cnt++;
                    state[nx][ny].Y = FLOWER;
                }
            }
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> g >> r;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2)
                cand.push_back({i, j});
        }
    }
    candsz = cand.size();
    fill(brute + candsz - g - r, brute + candsz - r, GREEN);
    fill(brute + candsz - r, brute + candsz, RED);
    int mx = 0;
    do {
        mx = max(mx, solve());
    }while(next_permutation(brute, brute + candsz));
    cout << mx << '\n';
    
    return 0;
}
