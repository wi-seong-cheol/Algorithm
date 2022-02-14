//
//  main.cpp
//  1026
//
//  Created by wi_seong on 2022/02/14.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int a[51], b[51];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    sort(a, a+n);
    sort(b, b+n, greater<>());
    int res = 0;
    for(int i = 0; i < n; i++)
        res += a[i] * b[i];
    cout << res;
    
    return 0;
}
