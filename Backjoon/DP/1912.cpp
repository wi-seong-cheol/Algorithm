//
//  1912.cpp
//  main
//
//  Created by wi_seong on 2022/03/10.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int d[1000001];
int a[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        d[i] = a[i];
    }
    for(int i = 0; i < n; i++)
        d[i] = max(d[i], d[i - 1] + a[i]);
    cout << *max_element(d, d + n);
    return 0;
}
