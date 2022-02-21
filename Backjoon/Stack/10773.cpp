//
//  10773.cpp
//  main
//
//  Created by wi_seong on 2022/02/21.
//

#include <iostream>
#include <stack>

using namespace std;
int k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k;
    stack<int> s;
    
    while(k--) {
        int n; cin >> n;
        if(n == 0) {
            if(!s.empty()) s.pop();
        } else {
            s.push(n);
        }
    }
    int sum = 0;
    while(!s.empty()) {
        sum += s.top();
        s.pop();
    }
    cout << sum;
    
    return 0;
}
