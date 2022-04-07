//
//  2869.cpp
//  main
//
//  Created by wi_seong on 2022/04/07.
//

#include <iostream>

using namespace std;
int a, b, v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a >> b >> v;
    int d = 1;
    d += (v - a) / (a - b);
    if((v - b) % (a - b) != 0) d++;
    if(a >= v) cout << 1;
    else cout << d;
    
    return 0;
}
