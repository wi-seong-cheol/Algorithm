//
//  7662.cpp
//  main
//
//  Created by wi_seong on 2022/02/17.
//

#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        multiset<int> ms;
        int k; cin >> k;
        while(k--) {
            char op;
            int n;
            cin >> op >> n;
            if(op == 'I') {
                ms.insert(n);
            } else {
                if(ms.empty()) continue;
                if(n == 1) ms.erase(prev(ms.end()));
                else ms.erase(ms.begin());
            }
        }
        if(ms.empty()) cout << "EMPTY" << '\n';
        else cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
    }
    
    return 0;
}
