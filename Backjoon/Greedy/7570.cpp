//
//  7570.cpp
//  main
//
//  Created by wi_seong on 2022/03/25.
//

#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1e6 + 2;
int n;
int d[MAX];
int chainMaxLIS;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        d[x] = d[x - 1] + 1;
        chainMaxLIS = max(chainMaxLIS, d[x]);
    }
    cout << n - chainMaxLIS;
    
    return 0;
}
