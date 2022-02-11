//
//  main.cpp
//  2579
//
//  Created by wi_seong on 2022/02/11.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int stairs[301];
int d[301][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i = 1; i <= n; i++)
        cin >> stairs[i];
    
    d[1][1] = stairs[1]; d[1][2] = 0;
    d[2][1] = stairs[2]; d[2][2] = stairs[1] + stairs[2];
    
    for(int i = 3; i <= n; i++) {
        d[i][1] = max(d[i-2][1], d[i-2][2]) + stairs[i];
        d[i][2] = d[i-1][1] + stairs[i];
    }
    cout << max(d[n][1], d[n][2]);
    
    return 0;
}
