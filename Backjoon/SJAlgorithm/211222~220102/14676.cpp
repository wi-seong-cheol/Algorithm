//
//  main.cpp
//  14676
//
//  Created by wi_seong on 2021/12/28.
//

#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, K; cin >> N >> M >> K;
    int inDegree[MAX], construct[MAX];
    vector<int> adj[MAX];
    
    for(int i = 0; i < M; i++) {
        int U, V; cin >> U >> V;
        adj[U].push_back(V);
        inDegree[V]++;
    }
    
    int op,a;
    bool pass = true;
    
    for(int i = 0; i < K; i++) {
        cin >> op >> a;
        if(op == 1) {
            if(inDegree[a] == 0) {
                construct[a]++;
                if(construct[a] == 1) {
                    for(int j = 0; j < adj[a].size(); j++) {
                        inDegree[adj[a][j]]--;
                    }
                }
            } else {
                pass = false;
            }
        } else {
            if(construct[a] > 0) {
                construct[a]--;
                if(construct[a] == 0) {
                    for(int j = 0; j < adj[a].size(); j++) {
                        inDegree[adj[a][j]]++;
                    }
                }
            } else {
                pass = false;
            }
        }
    }
    
    if(pass) {
        cout << "King-God-Emperor" << '\n';
    } else {
        cout << "Lier!" << '\n';
    }
    
    return 0;
}
