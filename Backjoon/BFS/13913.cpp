//
//  13913.cpp
//  main
//
//  Created by wi_seong on 2022/02/23.
//

#include <iostream>
#include <queue>
#include <stack>

using namespace std;
int n, k;
const int MX = 200000;
int dist[MX+2];
int route[MX+2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    fill(dist, dist+MX, -1);
    queue<int> Q;
    Q.push(n);
    dist[n] = 0;
    while(dist[k] == -1) {
        auto cur = Q.front(); Q.pop();
        for(auto nxt : {cur+1, cur-1, cur*2}) {
            if(nxt < 0 || nxt >= MX || dist[nxt] != -1) continue;
            route[nxt] = cur;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
    cout << dist[k] << '\n';
    deque<int> track = {k};
    while (track.front() != n)
        track.push_front(route[track.front()]);
    for (int p : track) cout << p << ' ';
    
    return 0;
}
