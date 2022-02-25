//
//  1992.cpp
//  main
//
//  Created by wi_seong on 2022/02/25.
//

#include <iostream>

using namespace std;
int board[64][64];

void quad(int n, int y, int x) {
    if(n == 1) {
        cout << board[y][x];
        return;
    }
    bool zero = true, one = true;
    for(int i = y; i < y + n; i++)
        for(int j = x; j < x + n; j++)
            if(board[i][j]) zero = false;
            else one = false;
    if(zero) cout << 0;
    else if(one) cout << 1;
    else {
        cout << '(';
        quad(n / 2, y, x);
        quad(n / 2, y, x + n / 2);
        quad(n / 2, y + n / 2, x);
        quad(n / 2, y + n / 2, x + n / 2);
        cout << ')';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < n; j++)
            board[i][j] = s[j] - '0';
    }
    quad(n,0,0);
    
    return 0;
}
