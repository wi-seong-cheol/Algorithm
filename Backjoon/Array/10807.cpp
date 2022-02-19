//
//  10807.cpp
//  main
//
//  Created by wi_seong on 2022/02/19.
//

#include <iostream>

using namespace std;
int n, v;
int arr[201];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--) {
        int a; cin >> a;
        arr[a + 100]++;
    }
    cin >> v;
    cout << arr[v+100];
    
    return 0;
}
