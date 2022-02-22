//
//  10799.cpp
//  main
//
//  Created by wi_seong on 2022/02/22.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s; cin >> s;
    int ans = 0;
    stack<char> p;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            p.push('(');
        } else {
            if(s[i-1] == '(') {
                p.pop();
                ans += p.size();
            } else {
                p.pop();
                ans++;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
