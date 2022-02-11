//
//  main.cpp
//  7795
//
//  Created by wi_seong on 2022/02/11.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int t;
int a[20001];
int b[20001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < m; i++)
            cin >> b[i];
        sort(a, a + n);
        sort(b, b + m);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = m - 1; j >= 0; j--) {
                if(a[i] > b[j]) {
                    cnt += j + 1;
                    break;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
