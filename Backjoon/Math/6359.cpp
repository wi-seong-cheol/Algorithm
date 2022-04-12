//
//  6359.cpp
//  main
//
//  Created by wi_seong on 2022/04/12.
//

#include <iostream>

using namespace std;
bool state[101];

void seive(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j += i) {
            state[j] ? state[j] = false : state[j] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        fill(state, state + n + 1, false);
        seive(n);
        int cnt = 0;
        for(int i = 1; i <= n; i++)
            if(state[i]) cnt++;
        cout << cnt << '\n';
    }
    
    return 0;
}
