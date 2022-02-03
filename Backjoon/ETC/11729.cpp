//
//  main.cpp
//  11729
//
//  Created by wi_seong on 2022/02/07.
//

#include <iostream>

using namespace std;

void hanoi(int a, int b, int n) {
    if(n == 1) {
        cout << a << ' ' << b << '\n';
        return;
    }
    hanoi(a, 6-a-b, n-1);
    cout << a << ' ' << b << '\n';
    hanoi(6-a-b, b, n-1);
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n; cin >> n;
    cout << (1<<n) - 1 << '\n';
    hanoi(1, 3, n);
    return 0;
}
