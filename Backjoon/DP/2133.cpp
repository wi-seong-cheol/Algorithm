//
//  2133.cpp
//  main
//
//  Created by wi_seong on 2022/03/10.
//

#include <iostream>

using namespace std;
int n;
int d[31];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[0] = 1; d[2] = 3;
    for(int i = 3; i <= n; i++) {
        d[i] += d[i - 2] * 3;
        for(int j = i - 4; j >= 0; j -= 2)
            d[i] += d[j] * 2;
    }
    cout << d[n];
    return 0;
}
