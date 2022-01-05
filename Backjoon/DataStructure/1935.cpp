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
    
    int N; cin >> N;
    vector<double> s;
    stack<char> cal;
    
    string str; cin >> str;
    
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            cal.push(str[i]);
        } else {
            s.push_back((double)str[i]);
        }
    }
    for(int i = 0; i < N; i++) {
        int a; cin >> a;

        for(int j = 0; j < s.size(); j++) {
            if(((double)'A' + i) == s.at(j)) {
                s.at(j) = a;
            }
        }
    }
    
    while(!cal.empty()) {
        if (cal.top() == '+') {
            double a = s.back();
            s.pop_back();
            double b = s.back();
            s.pop_back();
            double res = b + a;
            s.push_back(res);
        } else if (cal.top() == '-') {
            double a = s.back();
            s.pop_back();
            double b = s.back();
            s.pop_back();
            double res = b - a;
            s.push_back(res);
        } else if (cal.top() == '*') {
            double a = s.back();
            s.pop_back();
            double b = s.back();
            s.pop_back();
            int res = b * a;
            s.push_back(res);
        } else if (cal.top() == '/') {
            double a = s.back();
            s.pop_back();
            int b = s.back();
            s.pop_back();
            double res = b / a;
            s.push_back(res);
        }
        cal.pop();
    }
//    while(!s.empty()) {
//        cout << s.back() << ' ';
//        s.pop_back();
//    }
    cout << s.front();
    
    return 0;
}
