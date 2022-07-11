//
//  B.cpp
//  Algorithm
//
//  Created by wi_seong on 2022/04/02.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define ll long long;

const int mod = 1'000'000'007;
int n, q;
int w[1001];
vector<vector<int>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> w[i];
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
    }
    
    return 0;
}
/*
 10 9 1
 1 9 10
 */
