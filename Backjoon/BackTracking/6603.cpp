//
//  6603.cpp
//  main
//
//  Created by wi_seong on 2022/03/02.
//

#include <iostream>
#include <algorithm>

using namespace std;
int k, arr[15];
bool mask[15];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        cin >> k;
        if(!k) break;
        for(int i = 0; i < k; i++)
            cin >> arr[i];
        fill(mask + 6, mask + k, true);
        do {
            for(int i = 0; i < k; i++)
                if(!mask[i]) cout << arr[i] << ' ';
            cout << '\n';
        } while(next_permutation(mask, mask + k));
        cout << '\n';
    }
    
    return 0;
}
