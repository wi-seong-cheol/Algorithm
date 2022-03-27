//
//  5052.cpp
//  main
//
//  Created by wi_seong on 2022/03/23.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int n;
string s[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n;
        bool ans = true;
        for(int i = 0; i < n; i++) cin >> s[i];
        sort(s, s + n);
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == s[i+1].substr(0, s[i].length())) {
                ans = false;
                break;
            }
        }
        cout << (ans ? "YES":"NO") << '\n';
    } 
    
    return 0;
}
