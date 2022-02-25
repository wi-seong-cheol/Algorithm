//
//  9446.cpp
//  main
//
//  Created by wi_seong on 2022/02/25.
//

#include <iostream>
#include <queue>

using namespace std;
const int MX = 100005;
const int NOT_VISITED = 0;
const int CYCLE_IN = -1;
int n;
int arr[MX];
int state[MX];

void run(int x) {
    int cur = x;
    while(1) {
        state[cur] = x;
        cur = arr[cur];
        if(state[cur] == x) {
            while(state[cur] != CYCLE_IN) {
                state[cur] = CYCLE_IN;
                cur = arr[cur];
            }
            return;
        } else if(state[cur] != 0) return;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >>t;
    while(t--) {
        cin >> n;
        fill(state, state+n+1, 0);
        for(int i = 1; i <= n; i++)
            cin >> arr[i];
        int ans = 0;
        for(int i = 1; i <= n; i++)
            if(state[i] == NOT_VISITED) run(i);
        for(int i = 1; i <= n; i++)
            if(state[i] != CYCLE_IN) ans++;
        cout << ans << '\n';
    }

    return 0;
}
