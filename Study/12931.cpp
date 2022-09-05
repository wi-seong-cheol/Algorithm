//
//  12931.cpp
//  main
//
//  Created by wi_seong on 2022/09/05.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> arr1;
vector<int> arr2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int cnt = 0;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        arr1.push_back(x);
        arr2.push_back(0);
    }
    
    while(arr1 != arr2) {
        for(int i = 0; i < n; i++) {
            if(arr1[i] % 2 != 0) {
                arr1[i]--;
                cnt++;
            }
        }
        if(arr1 != arr2) cnt++;
        for(int i = 0; i < n; i++)
            arr1[i] /= 2;
    }
    cout << cnt;
    
    return 0;
}
