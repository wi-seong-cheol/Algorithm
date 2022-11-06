//
//  2262.cpp
//  main
//
//  Created by wi_seong on 2022/09/17.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> player;
int ans = 0x7f7f7f7f;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        player.push_back(x);
    }
    
    return 0;
}
