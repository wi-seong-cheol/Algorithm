//
//  5347_1.cpp
//  main
//
//  Created by wi_seong on 2022/04/12.
//

#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}

int lcm(int a, int b) {
    return a * (b / gcd(a, b));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        cout << lcm(a, b) << '\n';
    }
    
    return 0;
}
