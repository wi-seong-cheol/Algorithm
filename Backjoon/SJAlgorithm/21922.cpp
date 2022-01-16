//
//  main.cpp
//  21922
//
//  Created by wi_seong on 2022/01/16.
//

#include <iostream>
#include <algorithm>

using namespace std;

int ans = 0;
int N, M;
#define MAX 2001
int arr[MAX][MAX] = { 0, };


void solution() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if (arr[i][j] == 9) {
                
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    fill(&arr[0][0], &arr[MAX-1][MAX], -1);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    solution();
    cout << ans;
    
    return 0;
}
