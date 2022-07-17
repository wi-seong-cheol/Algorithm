//
//  2075.cpp
//  main
//
//  Created by wi_seong on 2022/11/04.
//

/*
 [Input]
 5
 12 7 9 15 5
 13 8 11 19 6
 21 10 26 31 16
 48 14 28 35 25
 52 20 32 41 49
 
 [Output]
 35
 */
// 시간복잡도: O()
// 최악시간:

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    bool debug = false;
    priority_queue<int, vector<int>, greater<int>> pq;
    int m = n * n;
    while(m--) {
        int x; cin >> x;
        if(pq.size() < n) pq.push(x);
        else {
            if(x > pq.top()) {
                pq.pop();
                pq.push(x);
            }
        }
    }
    cout << pq.top();
    
    return 0;
}
