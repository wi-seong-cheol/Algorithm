//
//  2193.cpp
//  main
//
//  Created by wi_seong on 2022/03/11.
//

#include <iostream>

using namespace std;
typedef long long ll;
int n;
ll d[100][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    d[1][1] = 1LL;
    for(int i = 2; i <= n; i++) {
        d[i][0] = d[i - 1][1] + d[i - 1][0];
        d[i][1] = d[i - 1][0];
    }
    cout << d[n][0] + d[n][1];
    
    return 0;
}
