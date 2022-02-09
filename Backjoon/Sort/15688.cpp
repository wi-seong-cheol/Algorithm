//
//  main.cpp
//  15688
//
//  Created by wi_seong on 2022/02/10.
//

#include <iostream>

using namespace std;

int freq[2000001] = {};
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int val; cin >> val;
        freq[val+1000000]++;
    }
    
    for(int i = 0; i <= 2000000; i++) {
        while(freq[i]--) {
            cout << i - 1000000 << ' ';
        }
    }
    
    return 0;
}
