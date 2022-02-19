//
//  2577.cpp
//  main
//
//  Created by wi_seong on 2022/02/19.
//

#include <iostream>

using namespace std;
int cnt[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, c; cin >> a >> b >> c;
    int n = a * b * c;
    while(n) {
        cnt[n%10]++;
        n /= 10;
    }
    for(int i = 0; i < 10; i++)
        cout << cnt[i] << '\n';
    
    return 0;
}
