//
//  1181_1.cpp
//  main
//
//  Created by wi_seong on 2022/03/04.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), [&](string a, string b) {
        int len1 = int(a.length());
        int len2 = int(b.length());
        if(len1 != len2) return len1 < len2;
        return a < b;
    });
    v.erase(unique(v.begin(), v.end()), v.end());
    for(auto s : v) cout << s << '\n';
    return 0;
}
