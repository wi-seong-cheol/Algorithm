//
//  main.cpp
//  5567
//
//  Created by wi_seong on 2021/12/28.
//

#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, result = 0; cin >> N >> M;
    vector<int> G[501];
    bool visited[501] = {false};
    queue<int> Q;
    
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    Q.push(1);
    visited[1] = true;
    for(int i = 0; i <= G[1].size(); i++) {
        int now = Q.front();
        Q.pop();
        for(int j = 0; j < G[now].size(); j++) {
            int next = G[now][j];
            if(visited[next] == false) {
                visited[next] = true;
                Q.push(next);
                result++;
            }
        }
    }
    
    cout << result << '\n';
    
    return 0;
}
