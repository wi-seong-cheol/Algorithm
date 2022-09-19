//
//  11066.cpp
//  main
//
//  Created by wi_seong on 2022/09/19.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define INF 0x6f6f6f6f

int n;
ll d[501][501]; // d[i][j] : i ~ j 까지 합치는 비용
int file[501];  // file의 크기
int sum[501];   // sum[i] : 1 ~ i 까지 파일의 합

/* chapter를 합치는 최소 비용?
 [Input]
 2
 4
 40 30 30 50
 15
 1 21 3 4 5 35 5 4 3 5 98 21 14 17 32
 
 [Output]
 300
 864
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> file[i];
            sum[i] = sum[i - 1] + file[i];
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n - i; j++) {
                d[j][i + j] = INF;
                for(int k = j; k < i + j; k++) {
                    d[j][i + j] = min(d[j][i + j], d[j][k] + d[k + 1][i + j] + sum[i + j] - sum[j - 1]);
                }
            }
        }
        cout << d[1][n] << '\n';
    }
    
    return 0;
}
