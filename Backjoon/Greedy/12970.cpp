//
//  12970.cpp
//  main
//
//  Created by wi_seong on 2022/09/23.
//

/*
 [Input]
 3 2
 
 [Output]
 ABB
 */
// 시간복잡도 : O(n)
// 최악 시간 : 50

// 가장 많은 순서쌍의 경우 : A*B*
// 가장 적은 순서쌍의 경우 : B*A*

#include <iostream>

using namespace std;

int n, k;
char s[51];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    int cnt = 0;
    if((n / 2) * (n / 2 + n % 2) < k) {
        cout << -1;
    } else if(k == 0) {
        for(int i = 0; i < n - 1; i++) cout << 'B';
        cout << 'A';
    } else {
        for(int i = 0, j = 1; i < n; i++) {
            if(i + j < n && cnt + n - i - j <= k) {
                cout << 'A';
                cnt += n - i - j++;
            } else {
                cout << 'B';
            }
        }
    }
    
    return 0;
}
