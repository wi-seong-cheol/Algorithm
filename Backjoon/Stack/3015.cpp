//
//  3015.cpp
//  Algorithm
//
//  Created by wi_seong on 2022/02/22.
//

#include <iostream>
#include <stack>

using namespace std;
#define X first
#define Y second
int n;
stack<pair<int, int>> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    long long ans = 0;
    while(n--) {
        int h; cin >> h;
        int cnt = 1;
        while(!s.empty() && s.top().X <= h) {
            ans += s.top().Y;
            if(s.top().X == h) cnt += s.top().Y;
            s.pop();
        }
        if(!s.empty()) ans++;
        s.push({h, cnt});
    }
    cout << ans;
    
    return 0;
}
