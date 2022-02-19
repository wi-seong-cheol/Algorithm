//
//  1919.cpp
//  main
//
//  Created by wi_seong on 2022/02/19.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int a[26], b[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s1, s2;
    cin >> s1 >> s2;
    
    for(auto c : s1)
        a[c-'a']++;
    for(auto c : s2)
        b[c-'a']++;
    int res = 0;
    for(int i = 0; i < 26; i++)
        if(a[i] != b[i]) res += abs(a[i] - b[i]);
    cout << res;
    
    return 0;
}
