//
//  2292.cpp
//  main
//
//  Created by wi_seong on 2022/04/06.
//

#include <iostream>

using namespace std;
int n, layer;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    n--;
    while (0 < (n -= 6*layer)) layer += 1;
    cout << ++layer;
    
    return 0;
}
