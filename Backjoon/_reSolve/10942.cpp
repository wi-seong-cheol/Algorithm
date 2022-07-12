//
//  10942.cpp
//  main
//
//  Created by wi_seong on 2022/10/03.
//
/*
 [Input]
 7
 1 2 1 3 1 2 1
 4
 1 3
 2 5
 3 3
 5 7
 [Output]
 1
 0
 1
 1
 */
// 시간복잡도 : O(n^2)
// 최악 시간: 4000000
#include <iostream>
#include <vector>

using namespace std;
int arr[2001];
int d[2001][2001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= n; i++) {
        d[i][i] = 1;
        if(arr[i - 1] == arr[i]) d[i - 1][i] = 1;
    }
    for(int gap = 2; gap < n; gap++) {
        for(int i = 1; i <= n - gap; i++) {
            int s = i;
            int e = i + gap;
            if(arr[s] == arr[e] && d[s + 1][e - 1]) d[s][e] = 1;
        }
    }
    int m; cin >> m;
    while(m--) {
        int s, e; cin >> s >> e;
        cout << d[s][e] << '\n';
    }
    
    return 0;
}
