//
//  main.cpp
//  10845
//
//  Created by wi_seong on 2022/01/16.
//

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    int tc; cin >> tc;
    queue<int> Q;
    
    while(tc--) {
        string op; cin >> op;
        
        if (op == "push") {
            int d; cin >> d;
            Q.push(d);
        } else if (op == "pop") {
            if(Q.empty()) cout << -1 << '\n';
            else {
                cout << Q.front() << '\n';
                Q.pop();
            }
        } else if (op == "size") {
            cout << Q.size() << '\n';
        } else if (op == "empty") {
            cout << Q.empty() << '\n';
        } else if (op == "front") {
            if(Q.empty()) cout << -1 << '\n';
            else cout << Q.front() << '\n';
        } else if (op == "back") {
            if(Q.empty()) cout << -1 << '\n';
            else cout << Q.back() << '\n';
        }
    }
    
    return 0;
}
