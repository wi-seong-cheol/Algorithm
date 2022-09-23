//
//  2096.cpp
//  main
//
//  Created by wi_seong on 2022/09/23.
//

// 시간복잡도: O()
// 최악 시간:

#include <iostream>
#include <vector>

using namespace std;
int n;
int board[100001][3];
vector<int> min_d;
vector<int> max_d;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    bool debug = false;
        
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < 3; i++) {
        min_d.push_back(board[0][i]);
        max_d.push_back(board[0][i]);
    }
    for(int i = 1; i < n; i++) {
        // 최댓값
        max_d.push_back(max(max_d[0], max_d[1]) + board[i][0]);
        max_d.push_back(max(max(max_d[0], max_d[1]), max_d[2]) + board[i][1]);
        max_d.push_back(max(max_d[1], max_d[2]) + board[i][2]);
        for(int i = 0; i < 3; i++) max_d.erase(max_d.begin());
        
        // 최솟값
        min_d.push_back(min(min_d[0], min_d[1]) + board[i][0]);
        min_d.push_back(min(min(min_d[0], min_d[1]), min_d[2]) + board[i][1]);
        min_d.push_back(min(min_d[1], min_d[2]) + board[i][2]);
        for(int i = 0; i < 3; i++) min_d.erase(min_d.begin());
        
        if(debug){
            for(auto d: min_d) {
                cout << d << ' ';
            }
            cout << '\n';
        }
    }
    
    cout << max(max(max_d[0], max_d[1]), max_d[2]) << ' ';
    cout << min(min(min_d[0], min_d[1]), min_d[2]);
    
    return 0;
}
