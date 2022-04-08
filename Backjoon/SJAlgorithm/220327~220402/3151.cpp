//
//  3151.cpp
//  main
//
//  Created by wi_seong on 2022/04/03.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int a[10001];
bool chk[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    long ans = 0;
    for(int i = 0; i < n - 2; i++){
        for(int j = i + 1 ; j < n - 1; j++){
            int temp = (-1) * (a[i] + a[j]);
            long first = lower_bound(a + j + 1, a + n, temp) - a;
            long last = upper_bound(a + j + 1, a + n, temp) - a;
            ans += last - first;
        }
    }
    cout << ans;
    
    return 0;
}
