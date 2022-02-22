//
//  2504.cpp
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
    stack<char> st;
    int num = 1;
    int ans = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            num *= 2;
            st.push(s[i]);
        }
        else if(s[i] == '[') {
            num *= 3;
            st.push(s[i]);
        }
        else if(s[i] == ')') {
            if(st.empty() || st.top() != '(') {
                cout << '0';
                return 0;
            }
            if(s[i-1] == '(') ans += num;
            st.pop();
            num /= 2;
        }
        else if(s[i] == ']') {
            if(st.empty() || st.top() != '[') {
                cout << '0';
                return 0;
            }
            if(s[i-1] == '[') ans += num;
            st.pop();
            num /= 3;
        }
    }
    if(!st.empty()) cout << '0';
    else cout << ans;
    return 0;
}
