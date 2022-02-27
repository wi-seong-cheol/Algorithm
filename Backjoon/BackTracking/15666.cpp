//
//  15666.cpp
//  main
//
//  Created by wi_seong on 2022/02/27.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int arr[10];
int num[10];
bool chk[10001];

void func(int k, int st) {
    if(k == m) {
        for(int i = 0; i < m; i++)
            cout << num[arr[i]] << ' ';
        cout << '\n';
        return;
    }
    for(int i = st; i < n; i++) {
        arr[k] = i;
        func(k + 1, i);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    int idx = 0;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        if(!chk[a]) {
            chk[a] = 1;
            num[idx++] = a;
        }
    }
    n = idx;
    sort(num, num + n);
    func(0, 0);
    
    return 0;
}
