//
//  2096.cpp
//  main
//
//  Created by wi_seong on 2022/09/23.
//

// 시간복잡도: O(n)
// 최악 시간: 100000

#include <iostream>
#include <vector>

using namespace std;
int n, tmp0, tmp2, min_d[3], max_d[3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    cin >> n;
    for(int i = 0; i < 3; i++) {
        int x; cin >> x;
        min_d[i] = max_d[i] = x;
    }
    for(int i = 1; i < n; i++) {
        int x, y, z; cin >> x >> y >> z;

        // 최댓값
        tmp0 = max_d[0]; tmp2 = max_d[2];
        max_d[0] = max(max_d[0], max_d[1]) + x;
        max_d[2] = max(max_d[1], max_d[2]) + z;
        max_d[1] = max(max(tmp0, max_d[1]), tmp2) + y;
        
        // 최솟값
        tmp0 = min_d[0]; tmp2 = min_d[2];
        min_d[0] = min(min_d[0], min_d[1]) + x;
        min_d[2] = min(min_d[1], min_d[2]) + z;
        min_d[1] = min(min(tmp0, min_d[1]), tmp2) + y;
    }
    
    cout << max(max(max_d[0], max_d[1]), max_d[2]) << ' ';
    cout << min(min(min_d[0], min_d[1]), min_d[2]);
    
    return 0;
}
