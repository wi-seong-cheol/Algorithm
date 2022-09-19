//
//  11049.cpp
//  main
//
//  Created by wi_seong on 2022/09/19.
//

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define INF 0x7f7f7f7f

int n;
int d[501][501];
vector<pair<int, int>> matrix;

/* 행렬을 곱하는 순서에 따른 최솟값
 [Input]
 3
 5 3
 3 2
 2 6
 
 [Output]
 90
 */

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    
    cin >> n;
    bool debug = true;
    matrix.push_back(make_pair(INF, INF));
    for(int i = 1; i <= n; i++) {
        int r, c; cin >> r >> c;
        matrix.push_back(make_pair(r, c));
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= n - i; j++) {
            d[j][i + j] = INF;
            for(int k = j; k <= i + j; k++) {
                d[j][i + j] = min(d[j][i + j], d[j][k] + d[k + 1][i + j] + matrix[j].first * matrix[k].second * matrix[i+j].second);
            }
        }
    }
    cout << d[1][n];
    
    return 0;
}
