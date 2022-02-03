//
//  main.cpp
//  DFS
//
//  Created by wi_seong on 2022/02/07.
//

#include <iostream>
#include <stack>

using namespace std;
#define X first
#define Y second
int board[502][502] = {
    {1,1,1,0,1,0,0,0,0,0},
     {1,0,0,0,1,0,0,0,0,0},
     {1,1,1,0,1,0,0,0,0,0},
     {1,1,0,0,1,0,0,0,0,0},
     {0,1,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0}
};
bool vis[502][502];
int n = 7, m = 10;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    stack<pair<int, int>> S;
    vis[0][0] = 1;
    S.push({0,0});
    while(!S.empty()) {
        pair<int, int> cur = S.top(); S.pop();
        cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = 1;
            S.push({nx, ny});
        }
    }
    
    return 0;
}
