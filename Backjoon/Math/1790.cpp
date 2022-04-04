//
//  1790.cpp
//  main
//
//  Created by wi_seong on 2022/04/04.
//

#include <iostream>
#include <string>

using namespace std;
#define ll long long
ll n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    int x = 1;
    while(n--) {
        string s = to_string(x);
        int len = int(s.length());
        if(len >= k) {
            cout << s[k - 1];
            return 0;
        }
        k -= len;
        x++;
    }
    cout << -1;
    
    return 0;
}
