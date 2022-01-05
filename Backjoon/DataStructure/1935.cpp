//
//  main.cpp
//  1935
//
//  Created by wi_seong on 2022/01/05.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    string str;
    cin >> N >> str;
    
    vector<int> v(N);
    stack<double> s;
    
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    for(int i = 0; i < str.length(); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            s.push(v[str[i] - 'A']);
        } else {
            if (!s.empty()) {
                double tmp = s.top();
                s.pop();
                if (str[i] == '+') {
                    tmp += s.top();
                } else if (str[i] == '-') {
                    tmp = s.top() - tmp;
                } else if (str[i] == '*') {
                    tmp *= s.top();
                } else if (str[i] == '/') {
                    tmp = s.top() / tmp;
                }
                s.pop();
                s.push(tmp);
            }
        }
    }
    
    cout << fixed;
    cout.precision(2);
    cout << s.top() << '\n';
    
    return 0;
}
