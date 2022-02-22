//
//  3986.cpp
//  main
//
//  Created by wi_seong on 2022/02/23.
//

#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    int ans = 0;
    while(t--) {
        stack<char> st;
        string s; cin >> s;
        for(auto c : s) {
            if(!st.empty() && st.top() == c) st.pop();
            else st.push(c);
        }
        if(st.empty()) ans++;
    }
    cout << ans;
    return 0;
}
