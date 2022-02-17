//
//  1806.cpp
//  main
//
//  Created by wi_seong on 2022/02/17.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n, s;
int a[100005];
int mn = 0x7fffffff;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> a[i];
    int en = 0;
    int sum = a[0];
    for(int st = 0; st < n; st++) {
        while(en < n && sum < s) {
            en++;
            if(en != n) sum += a[en];
        }
        if(en == n) break;
        mn = min(mn, en - st + 1);
        sum -= a[st];
    }
    if(mn == 0x7fffffff) mn = 0;
    cout << mn;
    return 0;
}
