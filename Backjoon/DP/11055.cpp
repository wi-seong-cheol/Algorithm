//
//  11055.cpp
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
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        d[i] = arr[i];
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++)
            if(arr[i] > arr[j]) d[i] = max(d[i], d[j] + arr[i]);
    cout << *max_element(d, d + n);
    
    return 0;
}
