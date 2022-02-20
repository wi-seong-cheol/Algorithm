//
//  main.cpp
//  Test
//
//  Created by wi_seong on 2022/01/11.
//

#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
vector<pair<int, int>> adj[20005];
const int INF = 0x3f3f3f3f;
bool fix[20005];
int d[20005];
int V = 10;

void dijkstra_naive(int st) {
    fill(d, d + V + 1, INF);
    d[st] = 0;
    while(true) {
        int idx = -1;
        for(int i = 1; i <= V; i++) {
            if(fix[i]) continue;
            if(idx == -1) idx = i;
            else if(d[i] < d[idx]) idx = i;
        }
        if(idx == -1 || d[idx] == INF) break;
        fix[idx] = 1;
        for(auto nxt : adj[idx])
            d[nxt.Y] = min(d[nxt.Y], d[idx] + nxt.Y);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}
