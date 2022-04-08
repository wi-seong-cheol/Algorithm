//
//  3980.cpp
//  main
//
//  Created by wi_seong on 2022/04/02.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int a[12][12];
int isused[12];
int ans;

void func(int pos, int sum) {
    if(pos == 11) {
        ans = max(ans, sum);
        return;
    }
    for(int i = 0; i < 11; i++) {
        if(a[pos][i] == 0) continue;
        if(!isused[i]) {
            isused[i] = 1;
            func(pos + 1, sum + a[pos][i]);
            isused[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        for(int i = 0; i < 11; i++) {
            for(int j = 0; j < 11; j++) cin >> a[i][j];
        }
        memset(isused, 0, sizeof(isused));
        ans = 0;
        func(0, 0);
        cout << ans << '\n';
    }
    
    return 0;
}
