//
//  4796.cpp
//  main
//
//  Created by wi_seong on 2022/04/11.
//

#include <iostream>

using namespace std;
int l, p, v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i = 1;
    while(1) {
        cin >> l >> p >> v;
        if(l == 0 && p == 0 && v == 0) break;
        int ans = (v / p) * l + ((v % p) > l ? l : (v % p));
        cout << "Case " << i++ << ": " << ans << '\n';
    }
    
    return 0;
}
