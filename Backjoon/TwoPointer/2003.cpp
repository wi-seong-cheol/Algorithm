//
//  2003.cpp
//  main
//
//  Created by wi_seong on 2022/11/04.
//

/*
 [Input]
 4 2
 1 1 1 1
 
 [Output]
 3
 */
// 시간복잡도: O(n)
// 최악시간: 10,000

#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, answer = 0;
    vector<int> v;
    
    // MARK: Input
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    
    int en = 0;
    ll sum1, sum2;
    sum1 = sum2 = 0;
    for(int st = 0; st < n; st++) {
        while(en < n && sum2 - sum1 + v[en] < m) {
            sum2 += v[en];
            en++;
        }
        if(en == n) break;
        if(sum2 - sum1 + v[en] == m) answer++;
        sum1 += v[st];
    }
    cout << answer;
    
    return 0;
}

