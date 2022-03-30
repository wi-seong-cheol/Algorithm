//
//  1476.cpp
//  main
//
//  Created by wi_seong on 2022/03/30.
//

#include <iostream>

using namespace std;
int E, S, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> E >> S >> M;
    int a, b, c, res;
    a = b = c = res = 1;
    while(1) {
        if(a == E && b == S && c == M) break;
        res++;
        a++;
        b++;
        c++;
        if(a == 16) a = 1;
        if(b == 29) b = 1;
        if(c == 20) c = 1;
    }
    cout << res;
    
    return 0;
}
