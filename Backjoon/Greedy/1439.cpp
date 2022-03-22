//
//  1439.cpp
//  main
//
//  Created by wi_seong on 2022/03/22.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s; cin >> s;
    int len = int(s.length());
    int cnt[2] = {0, 0};
    cnt[s[0] - '0']++;
    for(int i = 1; i < len; i++) if(s[i] != s[i-1]) cnt[s[i] - '0']++;
    cout << min(cnt[0], cnt[1]);
    
    return 0;
}
