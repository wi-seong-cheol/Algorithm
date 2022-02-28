//
//  16987.cpp
//  main
//
//  Created by wi_seong on 2022/02/28.
//

#include <iostream>
#include <vector>

using namespace std;
#define S first
#define W second
int n, mx, cnt;
int s[10], w[10];

void func(int k) {
    if(k == n) {
        mx = max(mx, cnt);
        return;
    }
    if(s[k] <= 0 || cnt == n - 1) {
        func(k + 1);
        return;
    }
    for(int i = 0; i < n; i++) {
        if(i == k || s[i] <= 0) continue;
        s[k] -= w[i];
        s[i] -= w[k];
        if(s[k] <= 0) cnt++;
        if(s[i] <= 0) cnt++;
        func(k + 1);
        if(s[k] <= 0) cnt--;
        if(s[i] <= 0) cnt--;
        s[k] += w[i];
        s[i] += w[k];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i] >> w[i];
    func(0);
    cout << mx;
    return 0;
}
