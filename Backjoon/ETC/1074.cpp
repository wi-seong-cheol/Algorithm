//
//  main.cpp
//  1074
//
//  Created by wi_seong on 2022/02/07.
//

#include <iostream>

using namespace std;

int func(int n, int r, int c) {
    if(n == 0) return 0;
    int half = 1 << (n-1);
    if(r < half && c < half) return func(n-1, r, c);
    if(r < half && c >= half) return half*half + func(n-1, r, c-half);
    if(r >= half && c < half) return 2*half*half + func(n-1, r-half, c);
    return 3*half*half + func(n-1, r-half, c-half);
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n, r, c; cin >> n >> r >> c;
    cout << func(n, r, c);
    
    return 0;
}
