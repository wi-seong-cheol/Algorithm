//
//  2004.cpp
//  main
//
//  Created by wi_seong on 2022/04/05.
//

#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long
ll n, m, two, five;

ll find(ll num, int p) {
    ll ret = 0, div = p;
    while(num / div) {
        ret += (num / div);
        div *= p;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    two = find(n, 2) - find(m, 2) - find((n - m), 2);
    five = find(n, 5) - find(m, 5) - find((n - m), 5);
    cout << min(two, five);
    
    return 0;
}
