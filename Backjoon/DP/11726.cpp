//
//  main.cpp
//  11726
//
//  Created by wi_seong on 2022/02/11.
//

#include <iostream>

using namespace std;
int n;
int d[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    d[1] = 1;
    d[2] = 2;
    for(int i = 3; i <= n; i++) {
        d[i] = (d[i-1] + d[i-2])  % 10007;
    }
    cout << d[n];
    
    return 0;
}
