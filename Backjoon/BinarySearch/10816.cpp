//
//  10816.cpp
//  main
//
//  Created by wi_seong on 2022/04/21.
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
        int low = lower_idx(target, n);
        int upper = upper_idx(target, n);
        cout << upper - low << ' ';
    }
    
    return 0;
}
