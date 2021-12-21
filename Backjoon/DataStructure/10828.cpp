//
//  main.cpp
//  second_main
//
//  Created by wi_seong on 2021/12/21.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N; cin >> N;
    string str;
    stack<int> s;
    
    for(int i=0; i<N; i++) {
        cin >> str;
        if(str == "push") {
            int X; cin >> X;
            s.push(X);
        } else if(str == "pop") {
            if(s.empty()) {
                cout << "-1\n";
            } else {
                cout << s.top() << "\n";
                s.pop();
            }
        } else if(str == "size") {
            cout << s.size() << "\n";
        } else if(str == "empty") {
            if(s.empty()) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else if(str == "top") {
            if(s.empty()) {
                cout << "-1\n";
            } else {
                cout << s.top() << "\n";
            }
        }
    }
    
    return 0;
}
