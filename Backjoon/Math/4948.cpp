//
//  4948.cpp
//  main
//
//  Created by wi_seong on 2022/04/11.
//

#include <iostream>
#include <vector>

using namespace std;
int n;
const int m = 123456 * 2;
vector<bool> state(m + 1, true);

void seive() {
    state[1] = false;
    for(int i = 2; i * i <= m; i++) {
        if(!state[i]) continue;
        for(int j = i * i; j <= m; j += i)
            state[j] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    seive();
    while(1) {
        cin >> n;
        if(n == 0) break;
        int cnt = 0;
        for(int i = n + 1; i <= 2 * n; i++)
            if(state[i]) cnt++;
        cout << cnt << '\n';
        
    }
    
    return 0;
}
