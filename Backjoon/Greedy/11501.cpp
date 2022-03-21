//
//  11501.cpp
//  main
//
//  Created by wi_seong on 2022/03/21.
//

#include <iostream>

using namespace std;
int n;
int a[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        int max_val = a[n - 1];
        long long ans = 0;
        for(int i = n - 2; i >= 0; i--) {
            if(max_val < a[i]) max_val = a[i];
            ans += max_val - a[i];
        }
        cout << ans << '\n';
    }
    
    return 0;
}
