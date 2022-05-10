//
//  14921.cpp
//  main
//
//  Created by wi_seong on 2022/05/09.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MX 100000001
int N;
vector<int> a;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    int ans = MX;
    for(int i = 0; i < N; i++) {
        int x = a[i];
        auto pos = lower_bound(a.begin(), a.end(), -x) - a.begin();
        if(pos < N && pos != i) {
            if(abs(ans) > abs(x + a[pos]))
               ans = x + a[pos];
        }
        
        pos = upper_bound(a.begin(), a.end(), -x) - a.begin() - 1;
        if(pos >= 0 && pos != i) {
            if(abs(ans) > abs(x + a[pos]))
               ans = x + a[pos];
        }
    }
    cout << ans;
    
    return 0;
}
