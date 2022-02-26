//
//  2448.cpp
//  main
//
//  Created by wi_seong on 2022/02/26.
//

#include <iostream>

using namespace std;
const int MAX = 1024 * 3 + 2;
char board[MAX][MAX * 2 - 1];

void fillStar(const int& x, const int& y) {
    board[x][y] = '*';
    board[x+1][y-1] = '*'; board[x+1][y+1] = '*';
    for(int i = y-2; i <= y+2; i++)
        board[x+2][i] = '*';
}

void solve(const int& n, const int& x, const int& y) {
    if(n == 3) {
        fillStar(x, y);
        return;
    }
    int ns = n/2;
    solve(ns, x, y);
    solve(ns, x+ns, y-ns);
    solve(ns, x+ns, y+ns);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        fill(board[i], board[i]+2*n-1, ' ');
    solve(n,0,n-1);
    for(int i = 0; i < n; i++)
        cout << board[i] << '\n';
    return 0;
}
