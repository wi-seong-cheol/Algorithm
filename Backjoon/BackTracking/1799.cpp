//
//  1799.cpp
//  main
//
//  Created by wi_seong on 2022/02/28.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int ans[2];
bool isused[2][20];
vector<pair<int, int>> board[2][20];

void bishop(int idx, int cnt, int color) {
    if(idx == 2 * n) {
        ans[color] = max(ans[color], cnt);
        return;
    }
    for(auto v : board[color][idx]) {
        int x, y;
        tie(x, y) = v;
        if(isused[color][x + y]) continue;
        isused[color][x + y] = 1;
        bishop(idx + 1, cnt + 1, color);
        isused[color][x + y] = 0;
    }
    bishop(idx + 1, cnt, color);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int d; cin >> d;
            if(d) board[(i + j + 1) % 2][n + i - j - 1].push_back({i, j});
        }
    }
    bishop(0, 0, 0);
    bishop(0, 0, 1);
    cout << ans[0] + ans[1];
    
    return 0;
}
