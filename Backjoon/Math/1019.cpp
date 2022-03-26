//
//  1019.cpp
//  main
//
//  Created by wi_seong on 2022/03/26.
//

#include <iostream>
#include <cmath>

using namespace std;
int n;
int a[10];

void subCounting(int num, int tenPower) {
    while (num) {
        a[num % 10] += tenPower;
        num /= 10;
    }
}

void solve() {
    int start = 1;
    int tenPower = 1;
    
    while(start <= n) {
        while(0 != start % 10 && start <= n) {
            subCounting(start, tenPower);
            start++;
        }
        if(n < start) return;
        while(9 != n % 10 && start <= n) {
            subCounting(n, tenPower);
            n--;
        }
        start /= 10;
        n /= 10;
        for(int i = 0; i < 10; i++)
            a[i] += (n - start + 1) * tenPower;
        tenPower *= 10;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    solve();
    
    for(int i = 0; i <= 9; i++)
        cout << a[i] << ' ';
    return 0;
}
