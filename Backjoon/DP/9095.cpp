//
//  main.cpp
//  9095
//
//  Created by wi_seong on 2022/02/11.
//

#include <iostream>

using namespace std;
int t;
int n;
int d[12];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    d[1] = 1; d[2] = 2; d[3] = 4;
    for(int i = 4; i < 11; i++)
        d[i] = d[i - 1] + d[i -2] + d[i - 3];

    cin >> t;
    while(t--) {
        cin >> n;
        cout << d[n] << '\n';
    }
    
    return 0;
}
