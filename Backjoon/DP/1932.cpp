//
//  1932.cpp
//  main
//
//  Created by wi_seong on 2022/03/10.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int d[501][501];
int tri[501][501];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cin >> tri[i][j];
            d[i][j] = tri[i][j];
        }
    }
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= i; j++)
            d[i][j] += max(d[i - 1][j - 1], d[i - 1][j]);
    cout << *max_element(d[n] + 1, d[n] + n + 1);
    
    return 0;
}
