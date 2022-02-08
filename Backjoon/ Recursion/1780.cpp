//
//  main.cpp
//  1780
//
//  Created by wi_seong on 2022/02/08.
//

#include <iostream>

using namespace std;
int n;
int board[2188][2188];
int cnt[3];

bool check(int x, int y, int n) {
    for(int i = x; i < x+n; i++)
        for(int j = y; j < y+n; j++)
            if(board[x][y] != board[i][j])
                return false;
    return true;
}

void func1(int x, int y, int z) {
    if(check(x, y, z)) {
        cnt[board[x][y] + 1] += 1;
        return;
    }
    int n = z/3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            func1(x + i * n, y + j * n, n);
    
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    func1(0,0,n);
    for(int i = 0; i < 3; i++)
        cout << cnt[i] << '\n';
    return 0;
}
