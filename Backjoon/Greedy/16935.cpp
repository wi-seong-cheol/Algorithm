//
//  16935.cpp
//  main
//
//  Created by wi_seong on 2022/10/06.
//

/*
 [Input]
 2 162
 [Output]
 5
 */
// 시간복잡도: O(logN)
// 최악시간: 9log10
#include <iostream>

using namespace std;
int a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    int x = b;
    int cnt = 1;
    while(a < x) {
        if(x % 2 == 0) {
            x /= 2;
            cnt++;
        } else if (x % 10 == 1) {
            x /= 10;
            cnt++;
        } else {
            x = 0;
            break;
        }
    }
    if(x == a) cout << cnt;
    else cout << -1;
    
    return 0;
}
