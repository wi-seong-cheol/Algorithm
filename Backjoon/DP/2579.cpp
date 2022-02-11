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
int all = 0;

// 2차원 배열 풀이
void twoArray() {
    int d[301][3];
    
    d[1][1] = stairs[1]; d[1][2] = 0;
    d[2][1] = stairs[2]; d[2][2] = stairs[1] + stairs[2];
    
    for(int i = 3; i <= n; i++) {
        d[i][1] = max(d[i-2][1], d[i-2][2]) + stairs[i];
        d[i][2] = d[i-1][1] + stairs[i];
    }
    cout << max(d[n][1], d[n][2]);
}

// 1차원 배열 풀이
void oneArray() {
    int d[301];
    
    d[1] = stairs[1];
    d[2] = stairs[2];
    d[3] = stairs[3];
    for(int i = 4; i <= n-1; i++)
        d[i] = min(d[i-3], d[i-2]) + stairs[i];
    cout << all - min(d[n-2], d[n-1]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> stairs[i];
        all += stairs[i];
    }
    
//    twoArray();
    oneArray();
    
    return 0;
}

