//
//  main.cpp
//  1931
//
//  Created by wi_seong on 2022/02/14.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> v;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int st, en; cin >> st >> en;
        v.push_back({en, st});
    }
    sort(v.begin(), v.end());
    int t = 0;
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(t > v[i].second) continue;
        res++;
        t = v[i].first;
    }
    cout << res;
    
    return 0;
}
