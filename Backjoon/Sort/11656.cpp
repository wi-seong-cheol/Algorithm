//
//  11656.cpp
//  main
//
//  Created by wi_seong on 2022/03/04.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s; cin >> s;
    int n = int(s.length());
    vector<string> v;
    for(int i = 0; i < n; i++) {
        string tmp = s.substr(i);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for(auto S : v) cout << S << '\n';
    
    return 0;
}
