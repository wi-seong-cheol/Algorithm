//
//  1057.cpp
//  main
//
//  Created by wi_seong on 2022/03/26.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, a, b;
    cin >> n >> a >> b;
    
    if (a > b) swap(a, b);
    int ans = 1;
    while(n) {
        if(a % 2 == 1 && a + 1 == b) {
            cout << ans << '\n';
            break;
        }
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        ans++;
        n /= 2;
    }
    
    return 0;
}
