//
//  3036.cpp
//  main
//
//  Created by wi_seong on 2022/04/10.
//

#include <iostream>

using namespace std;
int n, m;

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    n--;
    while(n--) {
        int x; cin >> x;
        int mod = gcd(m, x);
        cout << m / mod << '/' << x / mod << '\n';
    }
    
    return 0;
}
