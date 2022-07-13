//
//  11780.cpp
//  main
//
//  Created by wi_seong on 2022/09/26.
//

/*
 [Input]
 5
 14
 1 2 2
 1 3 3
 1 4 1
 1 5 10
 2 4 2
 3 4 1
 3 5 1
 4 5 3
 3 5 10
 3 1 8
 1 4 2
 5 1 7
 3 4 2
 5 2 4
 [Output]
 0 2 3 1 4
 12 0 15 2 5
 8 5 0 1 1
 10 7 13 0 3
 7 4 10 6 0
 0
 2 1 2
 2 1 3
 2 1 4
 3 1 3 5
 4 2 4 5 1
 0
 5 2 4 5 1 3
 2 2 4
 3 2 4 5
 2 3 1
 3 3 5 2
 0
 2 3 4
 2 3 5
 3 4 5 1
 3 4 5 2
 4 4 5 1 3
 0
 2 4 5
 2 5 1
 2 5 2
 3 5 1 3
 3 5 2 4
 0
 */

// 시간복잡도 : O(n^3)
// 최악 시간: 1000000

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int INF = 0x3f3f3f3f;
int n, m;
int d[101][101];
int nxt[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    nxt[i][j] = nxt[i][k];
                }
    for(int i = 1; i <= n; i++)
        fill(d[i], d[i] + n + 1, INF);
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
        nxt[a][b] = b;
    }
    for(int i = 1; i <= n; i++) d[i][i] = 0;
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                if(d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(d[i][j] == INF) cout << "0 ";
            else cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(d[i][j] == 0 || d[i][j] == INF) {
                cout << "0\n";
                continue;
            }
            vector<int> path;
            int st = i;
            while(st != j) {
                path.push_back(st);
                st = nxt[st][j];
            }
            path.push_back(j);
            cout << path.size() << ' ';
            for(auto x: path) cout << x << ' ';
            cout << '\n';
        }
    }
    return 0;
}
