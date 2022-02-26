//
//  1182.cpp
//  main
//
//  Created by wi_seong on 2022/02/26.
//

#include <iostream>

using namespace std;
int n, m;
int arr[21];
int isused[21];
int ans;
int sum;

void func(int nx, int k) {
    if(sum == m && nx != 0) ans++;
    for(int i = 0; i < n; i++) {
        if(!isused[i] && k <= i) {
            isused[i] = 1;
            sum += arr[i];
            func(nx + 1, i);
            isused[i] = 0;
            sum -= arr[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    func(0, 0);
    cout << ans;
    return 0;
}
