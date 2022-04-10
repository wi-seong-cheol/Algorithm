//
//  3343.cpp
//  main
//
//  Created by wi_seong on 2022/04/10.
//

#include <iostream>
#include <numeric>

using namespace std;
#define ll long long

void solve(ll n, ll a, ll b, ll c, ll d) {
    ll minimum_acount = 1e18 + 1;
    ll lcmAB = lcm(a, c);
    
    int a_bundle = 0;
    while(a * a_bundle < lcmAB) {
        if(n <= a * a_bundle) {
            if(b * a_bundle < minimum_acount)
                minimum_acount = b * a_bundle;
            break;
        }
        ll remainder = n - a * a_bundle;
        ll b_bundle = (remainder - 1) / c + 1;
        
        ll cost = b * a_bundle + d * b_bundle;
        if(cost < minimum_acount)
            minimum_acount = cost;
        
        a_bundle++;
    }
    cout << minimum_acount;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    if(a * d < b * c) solve(n, a, b, c, d);
    else solve(n, c, d, a, b);
    
    return 0;
}
