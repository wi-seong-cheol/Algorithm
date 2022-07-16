//
//  14698.cpp
//  main
//
//  Created by wi_seong on 2022/09/27.
//

/*
 [Input]
 2
 5
 3 10 2 8 14
 1
 13
 [Output]
 270950400
 1
 */
// 시간복잡도 :
// 최악 시간:

#include <iostream>
#include <queue>

using namespace std;
const long long int mod = 1'000'000'007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        long long int ans = 1;
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
        while(n--) {
            long long int x; cin >> x;
            pq.push(x);
        }
        while(pq.size() != 1) {
            long long int a = pq.top(); pq.pop();
            long long int b = pq.top(); pq.pop();
            ans *= ((a % mod) * (b % mod)) % mod;
            pq.push(a * b);
            ans %= mod;
        }
        cout << ans << '\n';
    }
    
    return 0;
}
