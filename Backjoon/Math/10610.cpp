//
//  10610.cpp
//  main
//
//  Created by wi_seong on 2022/03/27.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>

using namespace std;
string n;
vector<int> nums;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(auto c : n) nums.push_back(c - '0');
    sort(nums.begin(), nums.end(), greater<int>());
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum % 3 == 0 && nums.back() == 0)
        for(int n : nums) cout << n;
    else cout << -1;
    
    return 0;
}
