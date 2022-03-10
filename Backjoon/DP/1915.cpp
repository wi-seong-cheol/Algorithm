//
//  1915.cpp
//  main
//
//  Created by wi_seong on 2022/03/10.
//

#include <iostream>
#include <algorithm>

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
    int size = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(board[i][j] == '1'){
                d[i][j] = min({d[i-1][j], d[i][j-1], d[i-1][j-1]}) + 1;
                size = max(size, d[i][j]);
            }
        }
    }
    cout << size * size;
    
    return 0;
}
