//
//  2422.cpp
//  main
//
//  Created by wi_seong on 2022/03/28.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;
bool a[201][201];
int ans;
vector<int> result;

void combination(int size, int idx) {
    if(size == 3) {
        if(a[result[0]][result[1]]) return;
        else if(a[result[0]][result[2]]) return;
        ans++;
        return;
    }
    for(int i = idx; i <= n; i++) {
        if(a[idx][i]) continue;
        if(idx == i) continue;
        result.push_back(i);
        combination(size + 1, i);
        result.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        a[from][to] = true;
        a[to][from] = true;
    }
    combination(0, 0);
    cout << ans;
    
    return 0;
}
