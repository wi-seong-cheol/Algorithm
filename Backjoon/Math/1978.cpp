//
//  main.cpp
//  1978
//
//  Created by wi_seong on 2022/02/14.
//

#include <iostream>

using namespace std;
int n;

bool isPrime(int n) {
    if(n == 1) return false;
    for(int i = 2; i*i <= n; i++)
        if(n%i == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int cnt = 0;
    cin >> n;
    while(n--) {
        int a; cin >> a;
        cnt += isPrime(a);
    }
    cout << cnt;
    
    return 0;
}
