//
//  9084.cpp
//  main
//
//  Created by wi_seong on 2022/03/15.
//

#include <iostream>
#include <algorithm>

using namespace std;
int a[10001];
int d[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        int m; cin >> m;
        fill(d, d + 10001, 0);
        d[0] = 1;
        for(int i = 0; i < n; i++)
            for(int j = a[i]; j <= m; j++)
                d[j] += d[j - a[i]];
        cout << d[m] << '\n';
    }
    
    return 0;
}
