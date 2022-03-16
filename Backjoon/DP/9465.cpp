//
//  9465.cpp
//  Algorithm
//
//  Created by wi_seong on 2022/03/16.
//

#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  cin >> tc;
  while (tc--) {
    int N;
    cin >> N;
    vector<vector<int>> arr(N, vector<int>(2)), dp(N, vector<int>(2)); // N by 2 vector를 선언
    for (int j = 0; j < 2; j++)
      for (int i = 0; i < N; i++)
        cin >> arr[i][j];
    
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < 2; j++) {
        int v = 0;
        if (i > 1) v = max(dp[i - 2][0], dp[i - 2][1]);
        if (i > 0) v = max(v, dp[i - 1][1 - j]);
        dp[i][j] = v + arr[i][j];
      }
    }
    cout << max(dp[N - 1][0], dp[N - 1][1]) << '\n';
  }
}
