//
//  11931.cpp
//  main
//
//  Created by wi_seong on 2022/03/04.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n, greater<>());
    for(int i = 0; i < n; i++) cout << arr[i] << '\n';
    
    return 0;
}
