//
//  2225.cpp
//  main
//
//  Created by wi_seong on 2022/09/23.
//

// 시간복잡도: O(n * k)
// 최악 시간: 200 * 200

#include <iostream>
#include <algorithm>

using namespace std;
const int mod = 1'000'000'000;
int n, k, d[201][201];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i <= k; i++)
        d[1][i] = i;
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= k; j++)
            d[i][j] = (d[i - 1][j] + d[i][j - 1]) % mod;
    cout << d[n][k];
    return 0;
}
