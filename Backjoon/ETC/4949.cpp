//
//  main.cpp
//  4949
//
//  Created by wi_seong on 2022/01/28.
//

#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    while(true) {
        string s; getline(cin, s);
        if (s == ".") break;
        stack<char> st;
        bool isValid = true;
        for(auto c : s) {
            if (c == '(' || c == '[') st.push(c);
            else if (c == ')') {
                if(st.empty() || st.top() != '(') {
                    isValid = false;
                    break;
                }
                st.pop();
            } else if (c == ']') {
                if(st.empty() || st.top() != '[') {
                    isValid = false;
                    break;
                }
                st.pop();
            }
        }
        if (!st.empty()) isValid = false;
        if(isValid) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
    
    return 0;
}
