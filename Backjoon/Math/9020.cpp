//
//  9020.cpp
//  main
//
//  Created by wi_seong on 2022/04/14.
//

#include <iostream>
#include <algorithm>

using namespace std;
bool chk[10001];

void seive() {
    chk[1] = true;
    for(int i = 2; i < 10001; i++)
        if(!chk[i])
            for(int j = i * i; j < 10001; j += i)
                chk[j] = true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    seive();
    int t; cin >> t;
    while(t--) {
        int c; cin >> c;
        for (int a = c/2; 0 < a; a--){
            int b = c - a;
            if (!chk[a] && !chk[b]){
                cout << a << ' ' << b << '\n';
                break;
            }
        }
    }
    
    return 0;
}
