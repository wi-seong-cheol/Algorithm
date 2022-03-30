//
//  1456.cpp
//  main
//
//  Created by wi_seong on 2022/03/30.
//

#include <iostream>
#include <vector>

using namespace std;
#define ll long long
const ll MAX = 10000000 + 1;
ll minFactor[MAX];
ll A, B;
vector<ll> prime;

void eratosthenes() {
    minFactor[0] = minFactor[1] = -1;
    for(ll i = 2; i < MAX; i++)
        minFactor[i] = i;
    for(ll i = 2; i * i < MAX; i++)
        if(minFactor[i] == i)
            for(ll j = i * i; j < MAX; j += i)
                if(minFactor[j] == j)
                    minFactor[j] = i;
    for(ll i = 2; i < MAX; i++)
        if(minFactor[i] == i)
            prime.push_back(i);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> A >> B;
    eratosthenes();
    ll result = 0;
    for(int i = 0; i < prime.size(); i++) {
        ll num = prime[i];
        while(prime[i] <= B / num) {
            if(prime[i] * num >= A)
                result++;
            num *= prime[i];
        }
    }
    cout << result;
    
    return 0;
}
