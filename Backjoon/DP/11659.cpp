//
//  main.cpp
//  11659
//
//  Created by wi_seong on 2022/02/12.
//

#include <iostream>

using namespace std;
int n, m;
int arr[100005];
int d[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    d[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        d[i] = d[i-1] + arr[i];
    }
    
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        cout << d[b] - d[a-1] << '\n';
    }
    
    return 0;
}
