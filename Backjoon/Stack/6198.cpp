//
//  6198.cpp
//  Algorithm
//
//  Created by wi_seong on 2022/02/22.
//

#include <iostream>
#include <stack>

using namespace std;
#define ll long long
int n;
stack<ll> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    ll res = 0;
    while(n--) {
        ll h; cin >> h;
        
        while(!s.empty() && h >= s.top())
            s.pop();
        res += s.size();
        s.push(h);
    }
    cout << res;
    
    return 0;
}
