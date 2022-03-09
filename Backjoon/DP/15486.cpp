//
//  15486.cpp
//  main
//
//  Created by wi_seong on 2022/03/09.
//

#include <iostream>
#include <algorithm>

using namespace std;
const int MX = 1500001;
int n;
int t[MX];
int p[MX];
int d[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> t[i] >> p[i];
    for(int i = 0; i < n; i++) {
        d[i] = max(d[i], d[i - 1]);
        if(t[i] + i <= n + 1) d[i + t[i]] = max(d[i + t[i]], d[i] + p[i]);
    }
    cout << *max_element(d, d + n + 1);
    return 0;
}
