//
//  main.cpp
//  1629
//
//  Created by wi_seong on 2022/02/08.
//

#include <iostream>

using namespace std;
using ll = long long;

ll func1(ll a, ll b, ll  c) {
    if(b == 1) return a % c;
    ll val = func1(a, b/2, c);
    val = val * val % c;
    if(b%2 == 0) return val;
    return val * a % c;
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int a, b, c; cin >> a >> b >> c;
    cout << func1(a, b, c);
    
    return 0;
}
