//
//  1963.cpp
//  main
//
//  Created by wi_seong on 2022/04/05.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
vector<bool> prime(10001, true);

void seive() {
    prime[1] = false;
    for(int i = 2; i * i < 10000; i++)
        for(int j = i * i; j < 10000; j += i)
                prime[j] = false;
}

int vec2num(vector<int> &vec) {
    int ret = 0;
    int p10 = 1;
    for(int i = 0; i < 4; i++) {
        ret += vec[i] * p10;
        p10 *= 10;
    }
    return ret;
}

vector<int> num2vec(int num) {
    vector<int> ret;
    do ret.push_back(num % 10);
    while(num /= 10);
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    seive();
    int t; cin >> t;
    while(t--) {
        int s, e; cin >> s >> e;
        queue<int> Q;
        Q.push(s);
        int dist[10001];
        fill(dist, dist + 10001, -1);
        dist[s] = 0;
        while(!Q.empty()) {
            int cur = Q.front(); Q.pop();
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 10; j++) {
                    if(i == 3 && j == 0) continue;
                    vector<int> nxt_digits = num2vec(cur);
                    nxt_digits[i] = j;
                    int nxt = vec2num(nxt_digits);
                    if(!prime[nxt] || dist[nxt] != -1) continue;
                    dist[nxt] = dist[cur] + 1;
                    Q.push(nxt);
                }
            }
        }
        if(dist[e] == -1) cout << "Impossible\n";
        else cout << dist[e] << '\n';
    }
    
    return 0;
}
