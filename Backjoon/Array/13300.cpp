//
//  13300.cpp
//  main
//
//  Created by wi_seong on 2022/02/19.
//

#include <iostream>

using namespace std;
int r[2][6];
int n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    while(n--) {
        int a, b; cin >> a >> b;
        r[a][b-1]++;
    }
    int res = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 6; j++) {
            res += r[i][j]/k;
            if(r[i][j] % k) res++;
        }
    }
    cout << res;
    
    return 0;
}
