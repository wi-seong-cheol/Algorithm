//
//  5052.cpp
//  main
//
//  Created by wi_seong on 2022/03/23.
//

#include <iostream>
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
        bool chk = false;
        for(int i = 0; i < n; i++) {
            cin >> s[i];
            for(int j = 0; j < i; j++) {
                if(s[i].find(s[j]) != string::npos) {
                    chk = true;
                    break;
                }
            }
        }
        if(!chk) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    
    return 0;
}
