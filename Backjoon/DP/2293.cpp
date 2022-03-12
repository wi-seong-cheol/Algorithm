//
//  2293.cpp
//  main
//
//  Created by wi_seong on 2022/03/12.
//

#include <iostream>

using namespace std;
int n, k;
int a[10001];
int d[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    d[0] = 1;
    for(int i = 0; i < n; i++)
        for(int j = a[i]; j <= k; j++)
            d[j] += d[j - a[i]];
    cout << d[k];
    
    return 0;
}
