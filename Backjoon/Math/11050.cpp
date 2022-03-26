//
//  11050.cpp
//  main
//
//  Created by wi_seong on 2022/03/27.
//

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k; cin >> n >> k;
    int ret = 1;
    for(int i = 1; i <= n; i++) ret *= i;
    for(int i = 1; i <= k; i++) ret /= i;
    for(int i = 1; i <= n - k; i++) ret /= i;
    cout << ret;
    
    return 0;
}
