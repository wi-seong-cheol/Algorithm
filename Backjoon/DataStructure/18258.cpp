//
//  main.cpp
//  18258
//
//  Created by wi_seong on 2022/01/02.
//

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    queue<int> q;
    string s;
    int N; cin >> N;
    
    while(N--) {
        cin >> s;
        
        if(s == "push") {
            int a; cin >> a;
            q.push(a);
        } else if(s == "pop") {
            if(q.empty()) {
                cout << "-1" << '\n';
            } else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if(s == "size") {
            cout << q.size() << '\n';
        } else if(s == "empty") {
            cout << q.empty() << '\n';
        } else if(s == "front") {
            if(q.empty()) {
                cout << "-1" << '\n';
            } else {
                cout << q.front() << '\n';
            }
        } else {
            if(q.empty()) {
                cout << "-1" << '\n';
            } else {
                cout << q.back() << '\n';
            }
        }
    }
    return 0;
}
