//
//  7785.cpp
//  main
//
//  Created by wi_seong on 2022/02/17.
//

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;
int n;
unordered_set<string> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--) {
        string name, log; cin >> name >> log;
        if(log == "enter") s.insert(name);
        else s.erase(name);
    }
    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), greater<string>());
    for(auto x : ans) cout << x << '\n';
    
    return 0;
}
