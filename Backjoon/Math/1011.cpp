//
//  1011.cpp
//  main
//
//  Created by wi_seong on 2022/03/26.
//

#include <iostream>
#include <cmath>

using namespace std;
#define ll long long

ll solve(ll k) {
    return floor(2 * sqrt(k) - 1e-9);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int x, y; cin >> x >> y;
        cout << solve(y - x) << '\n';
    }
    
    return 0;
}
