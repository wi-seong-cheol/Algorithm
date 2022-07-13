//
//  14002.cpp
//  main
//
//  Created by wi_seong on 2022/09/28.
//

/*
 [Input]
 6
 10 20 10 30 20 50
 [Output]
 4
 10 20 30 50
 */

#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> ans;
int d[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        if(d[i - 1] < x) {
            d[i] = x;
            ans.push_back(x);
        } else {
            d[i] = d[i - 1];
        }
    }
    cout << ans.size() << '\n';
    for(auto x: ans)
        cout << x << ' ';
    
    return 0;
}
