//
//  11052.cpp
//  main
//
//  Created by wi_seong on 2022/03/06.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int d[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> d[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            d[i] = max(d[i - j] + d[j], d[i]);
    cout << d[n];
    return 0;
}
