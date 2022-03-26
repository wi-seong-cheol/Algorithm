//
//  10250.cpp
//  Algorithm
//
//  Created by wi_seong on 2022/03/26.
//

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int h, w, n;
        cin >> h >> w >> n;
        n--;
        int y = n % h + 1;
        int x = n / h + 1;
        if(x / 10 == 0) y *= 10;
        cout << y << x << '\n';
    }
    
    return 0;
}
