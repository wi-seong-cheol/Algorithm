//
//  main.cpp
//  Test
//
//  Created by wi_seong on 2022/01/11.
//

#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10];
int deg[10];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < 7; i++) {
        char u, v; cin >> u >> v;
        adj['A' - u].push_back('A' - v);
    }
    
    for(int i = 0; i < 7; ) {
        
    }
    
    return 0;
}
