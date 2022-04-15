//
//  10815.cpp
//  main
//
//  Created by wi_seong on 2022/04/15.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n, m, a[500001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    cin >> m;
    while(m--) {
        int x; cin >> x;
        cout << binary_search(a, a + n, x) << ' ';
    }
    
    return 0;
}
