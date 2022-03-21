//
//  11000.cpp
//  main
//
//  Created by wi_seong on 2022/03/17.
//

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n;
vector<pair<int,int>> event;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int s, t;
        cin >> s >> t;
        event.push_back({s, 1});
        event.push_back({t, -1});
    }
    sort(event.begin(), event.end());
    int ans = 0; // 필요한 강의실의 최대 개수
    int curtime = event[0].X; // 현재 시간
    int cur = 0; // 현재 시간에 열려있는 강의실의 개수
    int idx = 0; // 현재 보고있는 event에서의 인덱스
    while(true){
        while(idx < 2*n && event[idx].X == curtime){
            cur += event[idx].Y;
            idx++;
        }
        ans = max(ans, cur);
        if(idx == 2*n) break;
        curtime = event[idx].X;
    }
    cout << ans << '\n';
}
