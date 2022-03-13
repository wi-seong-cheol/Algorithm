//
//  main.cpp
//  20162
//
//  Created by wi_seong on 2022/02/06.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int a[1001];
int d[1001];

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        d[i] = a[i];
        for(int j = 1; j < i; j++) {
            if(a[i] > a[j] && d[j] + a[i] > d[i])
                d[i] = d[j] + a[i];
        }
    }
    cout << *max_element(d + 1, d + n + 1);
    return 0;
}
