//
//  1915.cpp
//  main
//
//  Created by wi_seong on 2022/10/05.
//

/*
 [Input]
 4 4
 0100
 0111
 1110
 0010
 [Output]
 4
 */
// 시간복잡도: O(N * M)
// 최악시간: 500 * 500 = 250000

#include <iostream>

using namespace std;

int n, m;
char board[1001][1001];
int d[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> board[i][j];
    int answer = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(board[i][j] == '1') {
                d[i][j] = min(d[i - 1][j - 1], min(d[i - 1][j], d[i][j - 1])) + 1;
                answer = max(answer, d[i][j]);
            }
        }
    }
    
    cout << answer * answer;
    
    return 0;
}
