//
//  2457.cpp
//  main
//
//  Created by wi_seong on 2022/03/25.
//

#include <iostream>
#include <vector>

using namespace std;
#define X first
#define Y second
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    vector<pair<int, int>> flower;
    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        flower.push_back({x1 * 100 + y1, x2 * 100 + y2});
    }
    int t = 301;
    int ans = 0;
    while(t < 1201) {
        int nxt_t = t;
        for(int i = 0; i < n; i++) {
            if(flower[i].X <= t && flower[i].Y >= nxt_t)
                nxt_t = flower[i].Y;
        }
        if(nxt_t == t) {
            cout << 0;
            return 0;
        }
        ans++;
        t = nxt_t;
    }
    cout << ans;
    
    return 0;
}
