//
//  11003.cpp
//  Algorithm
//
//  Created by wi_seong on 2022/02/22.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int n, l;
deque<pair<int, int>> dq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> l;
    
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        if(!dq.empty() && l == i - dq.front().Y)
            dq.pop_front();
        while(!dq.empty() && dq.back().X > t)
            dq.pop_back();
        dq.push_back({t, i});
        cout << dq.front().X << ' ';
    }
    return 0;
}
