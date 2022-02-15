//
//  18870.cpp
//  Algorithm
//
//  Created by wi_seong on 2022/02/15.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int a[1000001];
vector<int> uni;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        uni.push_back(a[i]);
    }
    sort(uni.begin(), uni.end());
    uni.erase(unique(uni.begin(), uni.end()), uni.end());
    for(int i = 0; i < n; i++)
        cout << lower_bound(uni.begin(), uni.end(), a[i]) - uni.begin() << ' ';
    return 0;
}
