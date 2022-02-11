//
//  main.cpp
//  11652
//
//  Created by wi_seong on 2022/02/11.
//

#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
int n;
ll arr[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    int cnt = 1;
    int mx = 1;
    ll val = arr[0];
    for(int i = 1; i <= n; i++) {
        if(arr[i] != arr[i-1]) {
            if(cnt > mx) {
                mx = cnt;
                val = arr[i-1];
            }
            cnt = 1;
        } else {
            cnt++;
        }
    }
    cout << val;
    
    return 0;
}
