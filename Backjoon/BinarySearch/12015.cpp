//
//  12015.cpp
//  main
//
//  Created by wi_seong on 2022/04/15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> a;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int input; cin >> input;
        if(a.empty() || a.back() < input) {
            a.push_back(input);
        } else {
            *lower_bound(a.begin(), a.end(), input) = input;
        }
    }
    cout << a.size();
    
    return 0;
}
