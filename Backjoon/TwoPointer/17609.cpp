//
//  17609.cpp
//  main
//
//  Created by wi_seong on 2022/11/03.
//

/*
 [Input]
 
 [Output]
 
 */
// 시간복잡도: O()
// 최악시간:

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    while(n--) {
        string s;
        cin >> s;
        int st = 0;
        int en = int(s.size())- 1;
        int cnt = 0;
        while(st < en) {
            if(cnt > 1) break;
            if(s[st] == s[en]) {    // 같을 때
                st++;
                en--;
            } else {
                if(s[st] == s[en - 1]) {
                    cnt++;
                    en--;
                } else if(s[st + 1] == s[en]) {
                    cnt++;
                    st++;
                } else {
                    cnt = 2;
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}
