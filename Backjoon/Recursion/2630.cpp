//
//  2630.cpp
//  main
//
//  Created by wi_seong on 2022/02/26.
//

#include <iostream>

using namespace std;
int board[128][128];
int ans[2];

bool chk(int n, int x, int y) {
    for(int i = x; i < x + n; i++)
        for(int j = y; j < y + n; j++)
            if(board[x][y] != board[i][j]) return false;
    return true;
}

void solve(int n, int x, int y) {
    if(chk(n, x, y)) {
        ans[board[x][y]]++;
        return;
    }
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            solve(n / 2, x + i * n / 2, y + j * n / 2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    solve(n,0,0);
    for(int i = 0; i < 2; i++)
        cout << ans[i] << '\n';
    return 0;
}
