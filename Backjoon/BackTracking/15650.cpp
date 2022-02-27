//
//  15650.cpp
//  main
//
//  Created by wi_seong on 2022/02/27.
//

#include <iostream>

using namespace std;
int n, m;
int arr[10];
int isused[10];

void func(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    int st  = 1;
    if(k != 0) st = arr[k-1] + 1;
    for(int i = st; i <= n; i++) {
        if(!isused[i]) {
            isused[i] = 1;
            arr[k] = i;
            func(k+1);
            isused[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    func(0);
    
    return 0;
}
