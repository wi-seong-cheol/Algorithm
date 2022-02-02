//
//  main.cpp
//  1697
//
//  Created by wi_seong on 2022/02/07.
//

#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second
int dist[100002];
int n, k;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    cin >> n >> k;
    fill(dist,dist + 100001,-1);
    dist[n] = 0;
    queue<int> Q;
    Q.push(n);
    while(dist[k] == -1) {
        int cur = Q.front(); Q.pop();
        for(int nxt: {cur-1, cur+1, 2*cur}) {
            if(nxt < 0 || nxt > 100000) continue;
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
    cout << dist[k];
    
    return 0;
}
