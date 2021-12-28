//
//  main.cpp
//  7347
//
//  Created by wi_seong on 2021/12/28.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, D[30]; cin >> T;

    for(int i = 0; i < T; i++) {
        cin >> N;
        for(int j = 0; j < N; j++) cin >> D[j];

        // 전체 디스크의 개수가 홀수이면 항상 검은 디스크와 흰 디스크를 분리할 수 있다.
        
        if(N%2 == 1) cout << "YES" << '\n';

        // 흰 디스크를 연속적으로 모으는 경우만 고려하자.
        // 흰 디스크를 연속적으로 모을 수 있다는 것은 짝수 번호를 가진 디스크의 수와 홀수 번호를 가진 디스크의 수가 2이상 차이나지 않는다는 것과 같다.
        else {
            int even = 0;
            int odd  = 0;

            for(int j = 0; j < N; j++) {
                if(D[j]) {
                    if(j%2) odd++;
                    else even++;
                }
            }

            if(abs(even - odd) <= 1) cout << "YES" << '\n';
            else cout << "NO" << '\n';
            
        }
    }

    return 0;
}
