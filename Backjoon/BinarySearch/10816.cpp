//
//  main.cpp
//  10816
//
//  Created by wi_seong on 2022/02/15.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int a[500001];

int lower_idx(int target, int len) {
    int st = 0, en = len;
    while(st < en) {
        int mid = (st+en)/2;
        if(a[mid] >= target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int upper_idx(int target, int len) {
    int st = 0, en = len;
    while(st < en) {
        int mid = (st+en)/2;
        if(a[mid] > target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    sort(a, a + n);
    while(m--) {
        int target; cin >> target;
        // STL X
//        cout << upper_idx(target, n) - lower_idx(target, n) << ' ';
        // STL O
        cout << upper_bound(a, a+n, target) - lower_bound(a, a+n, target) << ' ';
    }
    
    return 0;
}
