//
//  2170.cpp
//  main
//
//  Created by wi_seong on 2022/03/24.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define X first
#define Y second
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<pair<int, int>> events;
    cin >> n;
    while(n--) {
        int l, r; cin >> l >> r;
        events.push_back({l, 1});
        events.push_back({r, -1});
    }
    sort(events.begin(), events.end());
    int cnt = 0;
    int tot = 0;
    int loc = -1e9;
    for(auto event : events) {
        if(cnt > 0) tot += (event.X - loc);
        loc = event.X;
        cnt += event.Y;
    }
    cout << tot;
    
    return 0;
}
