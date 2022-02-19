//
//  1475.cpp
//  main
//
//  Created by wi_seong on 2022/02/19.
//

#include <iostream>
#include <algorithm>

using namespace std;
int cnt[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    while(n) {
        cnt[n%10]++;
        n /= 10;
    }
    int mx = 1;
    for(int i = 0; i < 10; i++) {
        if(i == 6 || i == 9) continue;
        mx = max(mx, cnt[i]);
    }
    mx = max(mx, (cnt[6]+cnt[9]+1)/2);
    cout << mx;
    
    return 0;
}
