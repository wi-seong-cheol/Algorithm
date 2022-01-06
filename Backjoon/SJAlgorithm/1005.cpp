//
//  main.cpp
//  1005
//
//  Created by wi_seong on 2022/01/05.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    
    int t; cin >> t;
    int D[1000];
    vector<vector<int>> G;
    
    for(int i = 0; i < t; i++) {
        int N, K; cin >> N >> K;
        G.resize(K);
        
        for(int j = 0; j < N; j++) {
            cin >> D[j];
        }
        
        for(int j = 0; j < K; j++) {
            int x, y; cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        int W; cin >> W;
        
    }
    
    return 0;
}
