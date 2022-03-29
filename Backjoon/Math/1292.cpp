//
//  1292.cpp
//  main
//
//  Created by wi_seong on 2022/03/29.
//

#include <iostream>

using namespace std;
int a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    cin >> a >> b;
    
    int i = 1;
    int cnt = 1;
    int ans = 0;
    while(1) {
        for(int j = 1; j <= cnt; j++) {
            if(i >= a) ans += cnt;
            if(i == b) {
                cout << ans;
                return 0;
            }
            i++;
        }
        cnt++;
    }
    
    
    return 0;
}
