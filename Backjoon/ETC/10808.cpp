//
//  10808.cpp
//  1158
//
//  Created by wi_seong on 2022/01/11.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    string S; cin >> S;
    vector<char> v;
    
    for(int i = 0; i < S.length(); i++) {
        v.push_back(S[i]);
    }
    
    for(int i = 0; i <= 'z' - 'a'; i++) {
        int cnt = 0;
        for(int ch : v) {
            if('a'+i == ch)
                cnt++;
        }
        cout << cnt << ' ';
    }
    
    return 0;
}
