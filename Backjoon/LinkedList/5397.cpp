//
//  5397.cpp
//  main
//
//  Created by wi_seong on 2022/02/20.
//

#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        string op; cin >> op;
        list<char> a;
        auto cur = a.begin();
        for(auto c : op) {
            if(c == '<') {
                if(cur != a.begin()) cur--;
            } else if(c == '>') {
                if(cur != a.end()) cur++;
            } else if(c == '-') {
                if(cur != a.begin()) {
                    cur--;
                    cur = a.erase(cur);
                }
            } else {
                a.insert(cur, c);
            }
        }
        for (auto c : a) cout << c;
        cout << '\n';
    }
    
    return 0;
}
