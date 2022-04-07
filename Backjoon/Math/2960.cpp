//
//  2960.cpp
//  Algorithm
//
//  Created by wi_seong on 2022/04/07.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<bool> v(n + 1, true);
    for(int i = 2; i < n + 1; i++) {
        if(!v[i]) continue;
        for(int j = i; j < n + 1; j += i) {
            if(!v[j]) continue;
            v[j] = false;
            k--;
            if(k == 0) {
                cout << j;
                return 0;
                
            }
        }
    }
    return 0;
}
