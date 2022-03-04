//
//  1181.cpp
//  Algorithm
//
//  Created by wi_seong on 2022/03/04.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    pair<int, string> s[n];
    for(int i = 0; i < n; i++) {
        string word; cin >> word;
        int len = int(word.length());
        s[i] = {len, word};
    }
    sort(s, s + n);
    for(int i = 0; i < n; i++)
        if(s[i].second != s[i - 1].second)
            cout << s[i].second << '\n';
    
    return 0;
}
