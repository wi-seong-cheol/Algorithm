//
//  main.cpp
//  1966
//
//  Created by wi_seong on 2022/01/07.
//

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    
    while(t--) {
        int N, M; cin >> N >> M;
        int target;
        
        queue<int> q;
        for(int j = 0; j < N; j++) {
            int a; cin >> a;
            if(a == j) target = a;
            q.push(a);
        }
        
        for(int j = 0; j < N; j++) {
            int a; cin >> a;
            q.push(a);
        }
    }
    return 0;
}
