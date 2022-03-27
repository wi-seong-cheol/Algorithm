//
//  1193.cpp
//  main
//
//  Created by wi_seong on 2022/03/27.
//

#include <iostream>

using namespace std;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    int i = 1;
    while (n > i) {
        n -= i;
        i++;
    }
    
    if (i % 2 == 1)
        cout << i + 1 - n << '/' << n << '\n';
    else
        cout << n << '/' << i + 1 - n << '\n';
    
    return 0;
}
