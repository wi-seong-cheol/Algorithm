//
//  5648.cpp
//  main
//
//  Created by wi_seong on 2022/03/05.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int n;
string st;
vector<long long> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> st;
        reverse(st.begin(), st.end());
        v.push_back(stoll(st));
    }
    sort(v.begin(), v.end());
    for(auto x : v) cout << x << '\n';

    return 0;
}
