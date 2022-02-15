//
//  main.cpp
//  1929
//
//  Created by wi_seong on 2022/02/14.
//

#include <iostream>
#include <vector>

using namespace std;
int m, n;
vector<bool> state(1000001, true);

void seive() {
    state[1] = false;
    for(int i = 2; i*i <= n; i++) {
        if(!state[i]) continue;
        for(int j = i*i; j <= n; j += i)
            state[j] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    seive();
    for(int i = m; i <= n; i++)
        if(state[i]) cout << i << '\n';
    return 0;
}
