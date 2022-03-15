//
//  4883.cpp
//  main
//
//  Created by wi_seong on 2022/03/14.
//

#include <iostream>
#include <algorithm>

using namespace std;
int d[100001][4];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k = 1;
    while(1) {
        int t; cin >> t;
        if(t == 0) break;
        for(int i = 0; i < t; i++)
            for(int j = 0; j < 3; j++)
                cin >> d[i][j];
        
        d[0][0] = 1001;
        d[0][2] += d[0][1];
        for(int i = 1; i < t; i++) {
            d[i][0] += min(d[i - 1][0], d[i - 1][1]);
            d[i][1] += min({d[i - 1][0], d[i - 1][1], d[i - 1][2], d[i][0]});
            d[i][2] += min({d[i - 1][1], d[i - 1][2], d[i][1]});
        }
        
        cout << k++ << ". " << d[t - 1][1] << '\n';
    }
    
    return 0;
}
