//
//  main.cpp
//  11728
//
//  Created by wi_seong on 2022/02/09.
//

#include <iostream>

using namespace std;
int n, m;
int arr1[1000001];
int arr2[1000001];
int tmp[1000001];

void merge() {
    int aidx = 0;
    int bidx = 0;
    for(int i = 0; i < n + m; i++) {
        if(bidx == m) tmp[i] = arr1[aidx++];
        else if(aidx == n) tmp[i] = arr2[bidx++];
        else if(arr1[aidx] <= arr2[bidx]) tmp[i] = arr1[aidx++];
        else tmp[i] = arr2[bidx++];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) cin >> arr1[i];
    for(int i = 0; i < m; i++) cin >> arr2[i];
    
    merge();
    for(int i = 0; i < n + m; i++) cout << tmp[i] << ' ';
    return 0;
}
