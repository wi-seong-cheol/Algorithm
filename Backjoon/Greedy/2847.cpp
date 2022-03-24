//
//  2847.cpp
//  main
//
//  Created by wi_seong on 2022/03/25.
//

#include <iostream>

using namespace std;
int n;
int a[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for(int i = n - 2; i >= 0; i--) {
        if(a[i] >= a[i + 1]) {
            ans += a[i] - a[i + 1] + 1;
            a[i] = a[i + 1] - 1;
        }
    }
    cout << ans;
    
    return 0;
}
