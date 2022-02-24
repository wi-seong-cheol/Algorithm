//
//  20304.cpp
//  main
//
//  Created by wi_seong on 2022/02/24.
//

#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <algorithm>

using namespace std;
int n, m;
int max_bit_size = 0;
int board[100001];
bool vis[100001];
queue<int> Q;
vector<int> P;
vector<int> discovered(1000001, 0);
vector<int> depth(1000001, 0);

void make_max_bit_size() {
    int check = n;
    
    while (1) {
        if(check / 2 != 0) {
            check /= 2;
            max_bit_size++;
        } else {
            max_bit_size++;
            break;
        }
    }
}

int solve() {
    for(int i = 0; i < P.size(); i++) {
        Q.push(P[i]);
        discovered[P[i]] = 1;
        depth[P[i]] = 0;
    }
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int i = 0; i < max_bit_size; i++) {
            int nxt = (cur ^ (1 << i));
            if(nxt > n || discovered[nxt] != 0) continue;
            discovered[nxt] = 1;
            depth[nxt] = depth[cur] + 1;
            Q.push(nxt);
        }
    }
    int ret = -1;
    for(int i = 0; i <= n; i++)
        ret = max(ret, depth[i]);
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int pi; cin >> pi;
        P.push_back(pi);
    }
    make_max_bit_size();
    cout << solve();
    
    return 0;
}
