//
//  11053.cpp
//  main
//
//  Created by wi_seong on 2022/03/07.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[1001];
int d[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) {
        d[i] = 1;
        for(int j = 0; j <= i; j++) {
            if(arr[i] > arr[j] && d[j] + 1 > d[i])
                d[i] = d[j] + 1;
        }
    }
    int mx = 0;
    for(int i = 0; i < n; i++)
        mx = max(mx, d[i]);
    cout << mx;
    return 0;
}
