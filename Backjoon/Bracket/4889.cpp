//
//  4889.cpp
//  main
//
//  Created by wi_seong on 2022/02/23.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int ord = 1;
    while(1) {
        string s; cin >> s;
        if(s[0] == '-') break;
        stack<char> st;
        int ans = 0;
        int cnt = 0;
        for(auto c : s) {
            if(c == '{') cnt++;
            else {
                cnt--;
                if(cnt == -1) {
                    cnt = 1;
                    ans++;
                }
            }
        }
        ans += cnt/2;
        cout << ord++ << ". " << ans << '\n';
    }
    
    return 0;
}
