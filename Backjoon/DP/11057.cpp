//
//  11057.cpp
//  main
//
//  Created by wi_seong on 2022/03/08.
//

#include <iostream>
#include <numeric>

using namespace std;
#define ll long long
int n;
ll d[1001][10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        d[i][0] = 1;
        for(int j  = 1; j < 10; j++)
            d[i][j] = (d[i][j - 1] + d[i - 1][j]) % 10007;
    }
    cout << accumulate(d[n], d[n] + 10, 0) % 10007;
    return 0;
}
