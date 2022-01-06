//
//  main.cpp
//  10799
//
//  Created by wi_seong on 2022/01/06.
//

#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    string input; cin >> input;
    stack<char> s;
    int total = 0;
    
    for(int i = 0; i < input.length(); i++) {
        if(input[i] == '(') {
            s.push(input[i]);
        } else if(input[i]==')' and input[i-1]=='('){
            s.pop();
            total += s.size();
        }
        else {
            total++;
            s.pop();
        }
    }
    cout << total;
    
    return 0;
}
