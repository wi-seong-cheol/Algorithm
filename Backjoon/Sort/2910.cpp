//
//  2910.cpp
//  main
//
//  Created by wi_seong on 2022/03/04.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define X first
#define Y second
int n, m;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.X > b.X;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    vector<pair<int, int>> arr;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        bool chk = 0;
        for(auto& ar : arr) {
            if(ar.Y == x) {
                ar.X++;
                chk = 1;
                break;
            }
        }
        if(!chk) arr.push_back({1, x});
    }
    stable_sort(arr.begin(), arr.end(), cmp);
    for (auto b : arr)
        while (b.X--) cout << b.Y << ' ';
    
    return 0;
}
