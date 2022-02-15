//
//  main.cpp
//  1920
//
//  Created by wi_seong on 2022/02/15.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int a[100005];

bool binarySearch(int target) {
    int st = 0, en = n - 1;
    while(st <= en) {
        int mid = (st + en)/2;
        if(a[mid] < target)
            st = mid + 1;
        else if (a[mid] > target)
            en = mid - 1;
        else return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    cin >> m;
    for(int i = 0; i < m; i++) {
        int target; cin >> target;
        cout << binarySearch(target) << '\n';
    }
    
    return 0;
}
