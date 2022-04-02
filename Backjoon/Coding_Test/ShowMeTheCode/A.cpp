//
//  A.cpp
//  main
//
//  Created by wi_seong on 2022/04/02.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;
int cost[11];
vector<pair<int, int>> disc[11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
        a[i] = i;
    }
    
    for(int i = 0; i < n; i++) {
        int p; cin >> p;
        for(int j = 0; j < p; j++) {
            int a, d; cin >> a >> d;
            disc[i].push_back({a, d});
        }
    }
    
    int ans = 10001;
    do {
        int tmp[11];
        copy(cost, cost + n, tmp);
        int total = 0;
        for(int i = 0; i < n; i++) {
            if(tmp[a[i]] <= 0) total++;
            else total += tmp[a[i]];
            for(int j = 0; j < disc[a[i]].size(); j++) {
                int x, y;
                tie(x, y) = disc[a[i]][j];
                tmp[x - 1] -= y;
            }
        }
        ans = min(ans, total);
    } while(next_permutation(a, a + n));
    cout << ans;
    
    return 0;
}
/*
 4
 10 20 30 40
 0
 0
 0
 1
 1 10
 */
