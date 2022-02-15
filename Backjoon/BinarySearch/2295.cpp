//
//  2295.cpp
//  main
//
//  Created by wi_seong on 2022/02/15.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, k;
int coin[1005];
vector<int> two;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> coin[i];
    sort(coin, coin + n);
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            two.push_back(coin[i] + coin[j]);
    sort(two.begin(), two.end());
    for(int i = n-1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(binary_search(two.begin(), two.end(), coin[i] - coin[j])) {
                cout << coin[i];
                return 0;
            }
        }
    }
            
    
    return 0;
}
