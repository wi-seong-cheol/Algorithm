//
//  1744.cpp
//  main
//
//  Created by wi_seong on 2022/03/24.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define ll long long
ll ans;

void seqSum(vector<int> v) {
    while(1 < v.size()) {
        ans += *(v.end() - 1) * *(v.end() - 2);
        v.pop_back();
        v.pop_back();
    }
    if(v.size()) ans += v.front();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    vector<int> seqP, seqN;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x == 1) ans++;
        else if(0 < x)
            seqP.push_back(x);
        else
            seqN.push_back(x);
    }
    
    sort(seqP.begin(), seqP.end());
    sort(seqN.begin(), seqN.end(), greater<>());
    seqSum(seqP);
    seqSum(seqN);
    cout << ans;
    
    return 0;
}
