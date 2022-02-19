//
//  11404.cpp
//  main
//
//  Created by wi_seong on 2022/02/19.
//

#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;
int n, m;
int cost[105][105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        fill(cost[i], cost[i] + n + 1, INF);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cost[a][b] = min(cost[a][b], c);
    }
    for(int i = 1; i <= n; i++) cost[i][i] = 0;
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(cost[i][j] == INF) cout << "0 ";
            else cout << cost[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
