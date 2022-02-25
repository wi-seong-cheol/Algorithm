//
//  5014.cpp
//  main
//
//  Created by wi_seong on 2022/02/25.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
const int MX = 1000000;
int F, S, G, U, D;
int dist[MX+1];

void bfs() {
    queue<int> Q;
    Q.push(S);
    dist[S] = 0;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if(cur == G) break;
        for(auto nxt : {cur+U, cur-D}) {
            if(nxt <= 0 || nxt > F || dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> F >> S >> G >> U >> D;
    fill(dist,dist+F+1,-1);
    bfs();
    if(dist[G] == -1) cout << "use the stairs";
    else cout << dist[G];
    
    return 0;
}
