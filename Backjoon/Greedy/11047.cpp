//
//  main.cpp
//  11047
//
//  Created by wi_seong on 2022/02/12.
//

#include <iostream>

using namespace std;
int n, k;
int a[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int ans = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = n - 1; i >= 0; i--) {
        ans += k / a[i];
        k %= a[i];
    }
    cout << ans;
    
    return 0;
}
