//
//  14002.cpp
//  main
//
//  Created by wi_seong on 2022/03/08.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n;
int arr[1001];
int d[1001];
int pre[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    fill(d, d + n, 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            if(arr[i] > arr[j] && d[i] < d[j] + 1){
                d[i] = d[j] + 1;
                pre[i] = j;
            }
        }
    }
    int mxd = d[1], mxi = 1;
    for(int i = 2; i <= n; i++) {
        if(mxd < d[i]) {
            mxi = i;
            mxd = d[i];
        }
    }
    deque<int> ans;
    int cur = mxi;
    while(cur) {
        ans.push_front(arr[cur]);
        cur = pre[cur];
    }
    cout << ans.size() << '\n';
    for(auto x : ans) cout << x << ' ';
    
    return 0;
}
