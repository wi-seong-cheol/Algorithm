//
//  1735.cpp
//  main
//
//  Created by wi_seong on 2022/04/01.
//

#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int a = x1 * y2 +  x2 * y1;
    int b = y1 * y2;
    int mod = gcd(a, b);
    a /= mod;
    b /= mod;
    cout << a << ' ' << b;
    
    return 0;
}
