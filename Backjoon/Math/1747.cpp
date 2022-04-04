//
//  1747.cpp
//  main
//
//  Created by wi_seong on 2022/04/04.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int n;

bool isprime(int n){
    if(n == 1) return 0;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return 0;
    }
    return 1;
}

bool ispalindrome(int n) {
    int tmp = n;
    int rev_n = 0;
    while(n > 0) {
        rev_n = 10 * rev_n + n % 10;
        n /= 10;
    }
    return rev_n == tmp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(!isprime(n) || !ispalindrome(n)) n++;
    cout << n;
    
    return 0;
}
