//
//  2573.cpp
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
int area[301][301];
int vis[301][301];
int n, m;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool OOB(int a, int b) {return a < 0 || a >= n || b < 0 || b >= m;}

void initvis() {
    for(int i = 0; i < n; i++)
        fill(vis[i], vis[i]+m, -1);
}

void melting() {
    int zero[301][301] = {0};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(area[i][j] == 0) continue;
            for(int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(!OOB(nx, ny) && area[nx][ny] == 0) zero[i][j]++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            area[i][j] = max(0, area[i][j] - zero[i][j]);
    }
}

int status() {
    int cnt1 = 0, cnt2 = 0;
    int x, y;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(area[i][j] != 0) {
                x = i;
                y = j;
                cnt1++;
            }
        }
    }
    if(cnt1 == 0) return 0;
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = 1;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        cnt2++;
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny] == 1 || area[nx][ny] == 0) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
    if(cnt1 == cnt2) return 1;
    else return 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> area[i][j];
    
    int year = 0;
    while(1) {
        year++;
        melting();
        initvis();
        int check = status();
        if(check == 0) {
            cout << 0;
            return 0;
        }
        else if(check == 1) continue;
        else break;
    }
    cout << year;
    
    return 0;
}
