//
//  1700.cpp
//  main
//
//  Created by wi_seong on 2022/03/23.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int n, k;
int a[101];
bool power[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 1; i <= k; i++) cin >> a[i];
    int ans = 0;
    int cnt = 0;
    for(int i = 1; i <= k; i++) {
        int cur = a[i];
        if(power[cur]) continue;
        if(cnt < n) {
            power[cur] = true;
            cnt++;
        } else {
            vector<pair<int, int>> idx;
            for(int x = 1; x <= k; x++) {
                if(!power[x]) continue;
                bool vis = false;
                for(int y = i + 1; y <= k; y++) {
                    if(a[y] == x) {
                        idx.push_back({y, x});
                        vis = true;
                        break;
                    }
                }
                if(!vis) idx.push_back({k + 1, x});
            }
            sort(idx.begin(), idx.end(), greater<pair<int, int>>());
            int target = idx[0].Y;
            power[target] = false;
            ans++;
            power[cur] = true;
        }
    }
    cout << ans;
    
    return 0;
}
