//
//  17103.cpp
//  main
//
//  Created by wi_seong on 2022/04/01.
//

#include <iostream>

using namespace std;
#define ll long long
const ll MAX = 1000000;
ll minFactor[MAX + 1];
bool prime[MAX + 1];

void eratosthenes() {
    minFactor[0] = minFactor[1] = -1;
    for(ll i = 2; i < MAX; i++)
        minFactor[i] = i;
    for(ll i = 2; i * i < MAX; i++)
        if(minFactor[i] == i)
            for(ll j = i * i; j < MAX; j += i)
                if(minFactor[j] == j)
                    minFactor[j] = i;
    for(ll i = 2; i < MAX; i++)
        if(minFactor[i] == i)
            prime[i] = 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    eratosthenes();
    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        int ans = 0;
        for(int i = 2; i <= (x + 1)/2; i++) {
            int y = x - i;
            if(y < i) continue;
            if(prime[y] && prime[i]) ans++;
        }
        cout << ans << '\n';
    }
    
    return 0;
}
