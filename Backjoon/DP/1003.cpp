//
//  1003.cpp
//  main
//
//  Created by wi_seong on 2022/03/05.
//

#include <iostream>

using namespace std;
int d[40][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        d[0][0] = 1; d[0][1] = 0;
        d[1][0] = 0; d[1][1] = 1;
        for(int i = 2; i <= n; i++) {
            d[i][0] = d[i - 1][0] + d[i - 2][0];
            d[i][1] = d[i - 1][1] + d[i - 2][1];
        }
        cout << d[n][0] << ' ' << d[n][1] << '\n';
    }
    
    return 0;
}
