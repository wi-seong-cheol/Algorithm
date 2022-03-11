//
//  2240.cpp
//  main
//
//  Created by wi_seong on 2022/03/11.
//

#include <iostream>
#include <algorithm>

using namespace std;
int t, w;
int a[1001];
int d[1001][32][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t >> w;
    for(int i = 1; i <= t; i++) cin >> a[i];
    for(int i = 1; i <= t; i++) {
        d[i][0][1] = d[i - 1][0][1] + (a[i] == 1 ? 1 : 0);
        for(int j = 1; j <= w; j++) {
            if(i < j) break;
            if(a[i] == 1) {
                d[i][j][1] = max(d[i - 1][j - 1][2], d[i - 1][j][1]) + 1;
                d[i][j][2] = max(d[i - 1][j - 1][1], d[i - 1][j][2]);
            } else {
                d[i][j][1] = max(d[i - 1][j - 1][2], d[i - 1][j][1]);
                d[i][j][2] = max(d[i - 1][j - 1][1], d[i - 1][j][2]) + 1;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= w; i++)
        ans = max({ans, d[t][i][1], d[t][i][2]});
    cout << ans;
    
    return 0;
}
