//
//  main.cpp
//  2631
//
//  Created by wi_seong on 2021/12/28.
//

#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M[201], dp[201]; cin >> N;
    int result = 0;
    
    for(int i = 0; i < N; i++) {
        cin >> M[i];
    }
    
    for(int i = 0; i < N; i++) {
        dp[i] = 1;
        
        for(int j = 0; j < i; j++) {
            if(M[j] < M[i] && dp[i] <= dp[j]) {
                dp[i]++;
            }
        }
        result = max(result, dp[i]);
    }
    
    cout << N - result;
    
    return 0;
}
