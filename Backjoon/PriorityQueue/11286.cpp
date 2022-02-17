//
//  11286.cpp
//  main
//
//  Created by wi_seong on 2022/02/18.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n;

class cmp {
public:
    bool operator() (int a, int b) {
        if(abs(a) != abs(b)) return abs(a) > abs(b);
        return a > 0 && b < 0;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<int, vector<int>, cmp> pq;
    cin >> n;
    while(n--) {
        int x; cin >> x;
        if(x == 0) {
            if(pq.empty()) cout << "0\n";
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else pq.push(x);
    }
    
    return 0;
}
