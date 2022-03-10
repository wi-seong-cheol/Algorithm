//
//  2156.cpp
//  main
//
//  Created by wi_seong on 2022/03/11.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int a[10001];
int d[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    d[1] = a[1]; d[2] = a[1] + a[2];
    for(int i = 3; i <= n; i++)
        d[i] = max({d[i - 1], d[i - 2] + a[i], d[i - 3] + a[i - 1] + a[i]});
    
    cout << d[n];
    
    return 0;
}
