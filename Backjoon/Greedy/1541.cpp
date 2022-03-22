//
//  1541.cpp
//  main
//
//  Created by wi_seong on 2022/03/22.
//

#include <iostream>
#include <string>

using namespace std;
int tmp, ans;
int sign = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s; cin >> s;
    for(char c : s) {
        if(c == '+' || c == '-') {
            ans += tmp * sign;
            if(c == '-') sign = -1;
            tmp = 0;
        } else {
            tmp *= 10;
            tmp += c - '0';
        }
    }
    ans += tmp * sign;
    cout << ans;
    
    return 0;
}
