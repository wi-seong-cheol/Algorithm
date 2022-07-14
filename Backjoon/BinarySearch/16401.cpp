//
//  16401.cpp
//  main
//
//  Created by wi_seong on 2022/05/10.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
int N, M;
vector<int> a;

bool solve(int x) {
    if(x == 0) return true;
    ll cnt = 0;
    for(int i = 0; i < N; i++)
        cnt += a[i] / x;
    return cnt >= M;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> M >> N;
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    
    int st = 0;
    int en = *max_element(a.begin(), a.end());
    while(st < en) {
        int mid = (st + en + 1) / 2;
        if(solve(mid))
            st = mid;
        else en = mid - 1;
    }
    cout << st;
    
    return 0;
}
