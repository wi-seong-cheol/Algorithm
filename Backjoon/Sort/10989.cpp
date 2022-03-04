//
//  10989.cpp
//  main
//
//  Created by wi_seong on 2022/03/04.
//

#include <iostream>
#include <algorithm>

using namespace std;
int arr[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        arr[num]++;
    }
    for(int i = 1; i < 10001; i++) {
        while(arr[i]--) {
            cout << i << '\n';
        }
    }
    return 0;
}
