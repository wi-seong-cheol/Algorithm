//
//  1038.cpp
//  main
//
//  Created by wi_seong on 2022/03/26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
vector<ll> v;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 1; i <= 1023; i++) {
        ll num = 0;
        int tmp_i = i;
        for(int idx = 9; idx >= 0; idx--) {
            if(tmp_i % 2 == 1)
                num = 10 * num + idx;
            tmp_i /= 2;
        }
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    cin >> n;
    if(n > 1022) cout << -1;
    else cout << v[n];
    return 0;
}
