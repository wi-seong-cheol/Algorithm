//
//  9657.cpp
//  main
//
//  Created by wi_seong on 2022/03/17.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int d[1005];
string ans[] = {"SK", "CY"};
int cand[] = {1, 3, 4};
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fill(d, d + 1005, -1);
    
    d[1] = 0; d[2] = 1; d[3] = 0; d[4] = 0;
    for(int i = 5; i <= n; i++) {
        for(int j : cand) {
            if(d[i - j] == 1) {
                d[i] = 0;
                break;
            }
            else d[i] = 1;
        }
    }
    
    cout << ans[d[n]];
    
    return 0;
}
