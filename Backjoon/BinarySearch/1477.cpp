//
//  1477.cpp
//  main
//
//  Created by wi_seong on 2022/04/29.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, l;
vector<int> p(51);

int binary_search() {
    int left = 1, right = l - 1;
    while (left <= right){
        int mid = (left + right)/2;
        int count = 0;
        for (int i = 1; i < n + 2; i++) {
            int section = p[i] - p[i-1];

            count += section / mid;
            if(section % mid == 0) count--;
        }

        if(count > m) left = mid + 1;
        else right = mid - 1;
    }
    return left;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> l;
    for(int i = 1; i <= n; i++) cin >> p[i];
    p[n+1] = l;
    sort(p.begin(), p.begin() + n + 1);
    cout << binary_search();

    return 0;
}
