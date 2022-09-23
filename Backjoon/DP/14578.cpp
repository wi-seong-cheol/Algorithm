//
//  14578.cpp
//  main
//
//  Created by wi_seong on 2022/09/23.
//

// 교란순열
// 시간복잡도 : O(n)
// 최악 시간: 100000

#include <iostream>

using namespace std;
#define ll long long
const ll mod = 1'000'000'007;
ll n, d[100001], f = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[0] = 1;
    for(ll i = 2; i <= n; i++) {
        f *= i;
        f %= mod;
        d[i] = (i - 1) * (d[i - 1] + d[i - 2]) % mod;
    }
    
    cout << (f * d[n]) % mod;
    return 0;
}
//#include <iostream>
//#define MOD 1000000007
//using namespace std;
//typedef long long ll;
//
//ll d[100002], f = 1;
//int main() {
//    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    ll n; cin >> n;
//    d[1] = 0, d[0] = 1;
//    for (ll i = 2; i <= n; i++) {
//        f *= i, f %= MOD;
//        d[i] = (i - 1) * (d[i - 1] + d[i - 2]) % MOD;
//    }
//    cout << (f * d[n]) % MOD;
//    return 0;
//}

/*  n = 2, res = 2
 
    n = 3, res = 12
 
    n = 4, res =
 
    n = 5, res =
*/
