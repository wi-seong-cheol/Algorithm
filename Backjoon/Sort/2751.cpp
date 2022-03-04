//
//  2751.cpp
//  main
//
//  Created by wi_seong on 2022/03/04.
//

#include <iostream>
#include <algorithm>

using namespace std;
const int MX = 2000000;
const int HALF = MX / 2;

int n;
bool chk[MX + 2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--) {
        int a; cin >> a;
        chk[a + HALF] = 1;
    }
    for(int i = 0; i <= MX; i++)
        if(chk[i]) cout << i - HALF << '\n';
    
    return 0;
}
