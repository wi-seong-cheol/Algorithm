//
//  11399.cpp
//  Algorithm
//
//  Created by wi_seong on 2022/03/21.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int a[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    for(int i = 0; i < n; i++) ans += a[i] * (n - i);
    cout << ans;
    
    return 0;
}
