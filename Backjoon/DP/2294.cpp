//
//  2294.cpp
//  main
//
//  Created by wi_seong on 2022/03/12.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n, k;
int a[10001];
int d[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    fill(d, d + 10001, 10001);
    d[0] = 0;
    for(int i = 0; i < n; i++)
        for(int j = a[i]; j <= k; j++)
            d[j] = min(d[j], d[j - a[i]] + 1);
    cout << (d[k] == 10001 ? -1 : d[k]);
    
    return 0;
}
