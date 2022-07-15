//
//  2157.cpp
//  main
//
//  Created by wi_seong on 2022/09/23.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n, m, k;
int r[301][301];    // r[i][j] : i에서 j로 갈 때 점수
int d[301][301];    // d[i][j] : i

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    
    for(int i = 0; i < k; i++) {
        int a, b, c; cin >> a >> b >> c;
        if(a > b) continue;
        r[a][b] = max(r[a][b], c);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 2; j <= n; i++) {
            
        }
    }
    cout << d[n][m];
    
    return 0;
}
/*
    1   2   3
 1  0   5   10
 2  0   0   3
 3  0   0   0
 
    1   2   3
 1  0   0   0
 2  5   5   0
 3  10  10  10
 */
