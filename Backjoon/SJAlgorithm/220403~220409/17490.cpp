//
//  17490.cpp
//  main
//
//  Created by wi_seong on 2022/04/08.
//

#include <iostream>
#include <vector>

using namespace std;
int a[1000001];
int n, m, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<pair<int, int>> v;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    
    return 0;
}
