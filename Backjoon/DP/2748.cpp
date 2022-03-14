//
//  2748.cpp
//  main
//
//  Created by wi_seong on 2022/03/14.
//

#include <iostream>

using namespace std;
#define ll long long
int n;
ll d[91];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    d[0] = 0; d[1] = 1;
    for(int i = 2; i <= n; i++)
        d[i] = d[i - 1] + d[i - 2];
    cout << d[n];
    
    return 0;
}
