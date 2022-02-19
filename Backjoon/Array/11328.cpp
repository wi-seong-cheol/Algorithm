//
//  11328.cpp
//  main
//
//  Created by wi_seong on 2022/02/19.
//

#include <iostream>
#include <string>

using namespace std;
int cnt1[26], cnt2[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    while(n--) {
        string a, b; cin >> a >> b;
        for(int i = 0; i < a.length(); i++) {
            cnt1[a[i] - 'a']++;
            cnt2[b[i] - 'a']++;
        }
        bool res = 1;
        for(int i = 0; i < 26; i++)
            if(cnt1[i] != cnt2[i]) {
                res = 0;
                break;
            }
        if(res) cout << "Possible" << '\n';
        else cout << "Impossible" << '\n';
        fill(cnt1, cnt1+26, 0);
        fill(cnt2, cnt2+26, 0);
    }
    
    return 0;
}
