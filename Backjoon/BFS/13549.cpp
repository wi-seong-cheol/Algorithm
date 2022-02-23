//
//  13549.cpp
//  main
//
//  Created by wi_seong on 2022/02/23.
//

#include <iostream>
#include <queue>

using namespace std;
int n, k;
const int LMT = 100001;
int board[LMT];
int ans = 0;
queue<int> Q;

void teleport(int num) {
    int tmp = num;
    if (!tmp) return;
    while (tmp < LMT && !board[k]) {
        if (!board[tmp]) {
            board[tmp] = board[num];
            Q.push(tmp);
            if (tmp == k) return;
        }
        tmp <<= 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    board[n] = 1;
    teleport(n);
    Q.push(n);
    while(!board[k]) {
        int cur = Q.front(); Q.pop();
        for(auto nxt : { cur + 1, cur - 1 }) {
            if (nxt < 0 || LMT <= nxt) continue;
            if (board[nxt]) continue;
            board[nxt] = board[cur] + 1;
            Q.push(nxt);
            teleport(nxt);
        }
    }
    cout << board[k] - 1;
    
    return 0;
}
