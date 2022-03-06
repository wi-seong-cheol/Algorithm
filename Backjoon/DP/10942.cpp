//
//  10942.cpp
//  main
//
//  Created by wi_seong on 2022/03/06.
//

#include <iostream>

using namespace std;
int n, m, s, e;
int arr[2001];
int d[2001][2001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= n; i++) {
        d[i][i] = 1;
        if(arr[i - 1] == arr[i]) d[i - 1][i] = 1;
    }
    for(int gap = 2; gap < n; gap++) {
        for(int i = 1; i <= n - gap; i++) {
            int s = i, e = i + gap;
            if(arr[s] == arr[e] && d[s + 1][e - 1]) d[s][e] = 1;
        }
    }
    cin >> m;
    while(m--) {
        cin >> s >> e;
        cout << d[s][e] << '\n';
    }
    
    return 0;
}
