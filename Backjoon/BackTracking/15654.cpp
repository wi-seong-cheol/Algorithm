//
//  15654.cpp
//  main
//
//  Created by wi_seong on 2022/02/27.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int arr[10];
int tmp[10];
bool isused[10];

void func(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++)
            cout << tmp[i] << ' ';
        cout << '\n';
    }
    for(int i = 0; i < n; i++) {
        if(!isused[i]) {
            tmp[k] = arr[i];
            isused[i] = 1;
            func(k + 1);
            isused[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    func(0);
    
    return 0;
}
