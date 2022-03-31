//
//  1676.cpp
//  main
//
//  Created by wi_seong on 2022/03/31.
//

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    int ans = 0;
    while(n) {
        ans += n / 5;
        n /= 5;
    }
    cout << ans;
    
    return 0;
}
