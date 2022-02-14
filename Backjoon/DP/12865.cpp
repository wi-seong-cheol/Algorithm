//
//  main.cpp
//  12865
//
//  Created by wi_seong on 2022/02/14.
//

#include <iostream>
#include <algorithm>

using namespace std;
#define weight first
#define value second
int n, k;
int d[101][100005];
pair<int, int> th[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> th[i].weight >> th[i].value;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(j >= th[i].weight)
                d[i][j] = max(d[i-1][j], d[i-1][j-th[i].weight] + th[i].value);
            else d[i][j] = d[i - 1][j];
        }
    }
    cout << d[n][k];
    
    return 0;
}
