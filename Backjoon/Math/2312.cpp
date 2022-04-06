//
//  2312.cpp
//  main
//
//  Created by wi_seong on 2022/04/06.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int cnt[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        fill(cnt, cnt + 100001, 0);
        int mod = 2;
        while(n != 1) {
            if(n % mod == 0) {
                cnt[mod]++;
                n /= mod;
            } else {
                mod++;
            }
        }
        for(int i = 2; i <= 100000; i++)
            if(cnt[i]) cout << i << ' ' << cnt[i] << '\n';
    }
    
    return 0;
}
