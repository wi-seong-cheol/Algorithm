//
//  main.cpp
//  12896
//
//  Created by wi_seong on 2022/01/03.
//

#include <iostream>
#include <queue>

using namespace std;

struct Info { int pos, road; };

void dfs(int start) {
    bool visited[501] = {false};
    
    
    
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<Info> g;
    
    for(int i =0; i < N-1; i++) {
        int u, v; cin >> u >> v;
        g.push_back({u, v});
        g.push_back({v, u});
    }
    
    
    
    return 0;
}
