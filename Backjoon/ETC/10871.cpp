//
//  10871.cpp
//  1158
//
//  Created by wi_seong on 2022/01/11.
//

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, X; cin >> N >> X;
    
    while(N--) {
        int a; cin >> a;
        if(a < X) cout << a << ' ';
    }
    
    return 0;
}
