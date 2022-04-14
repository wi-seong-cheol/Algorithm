//
//  9613_1.cpp
//  main
//
//  Created by wi_seong on 2022/04/14.
//

#include <iostream>

using namespace std;
#define ll long long

int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[101];
        ll ans = 0;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n-1; i++)
            for(int j = i + 1; j < n; j++)
                ans += gcd(a[i], a[j]);
        cout << ans << '\n';
    }
    
    return 0;
}
