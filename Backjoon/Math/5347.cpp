//
//  5347.cpp
//  main
//
//  Created by wi_seong on 2022/04/12.
//

#include <iostream>
#include <numeric>

using namespace std;

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
