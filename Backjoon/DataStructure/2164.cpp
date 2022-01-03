//
//  main.cpp
//  2164
//
//  Created by wi_seong on 2022/01/03.
//

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    int tmp;
    queue<int> q;
    
    for(int i = 0; i < N; i++) {
        q.push(i+1);
    }
    
    N--;
    while(N--) {
        q.pop();
        tmp = q.front();
        q.pop();
        q.push(tmp);
    }
    
    cout << q.front() << '\n';
    
    return 0;
}
