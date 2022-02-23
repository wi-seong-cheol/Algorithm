//
//  13549_1.cpp
//  main
//
//  Created by wi_seong on 2022/02/23.
//

#include <iostream>
#include <queue>

using namespace std;
int n, k;
const int MX = 200000;
int dist[MX + 2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    fill(dist, dist+MX, -1);
    deque<int> dq;
    dq.push_back(n);
    dist[n] = 0;
    while(!dq.empty()) {
        int cur = dq.front(); dq.pop_front();
        if(2*cur < MX && dist[2*cur] == -1) {
            dist[2*cur] = dist[cur];
            dq.push_back(2*cur);
        }
        for(auto nxt : {cur-1, cur+1}) {
            if(nxt < 0 || nxt >= MX || dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            dq.push_back(nxt);
        }
    }
    cout << dist[k];
    return 0;
}
