//
//  main.cpp
//  11497
//
//  Created by wi_seong on 2021/12/28.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T, N, result, L[10001]; cin >> T;
    
    while(T--) {
        cin >> N;
        result = 0;
        for(int i = 0; i < N; i++) {
            cin >> L[i];
        }
        // 정렬 후 2칸 떨어진 통나무끼리의 높이 차이들 중 최대를 구하면 이는 곳 난이도가 된다.
        sort(L, L + N);
        for(int i = 0; i < N - 2; i++) {
            result = max(result, abs(L[i] - L[i+2]));
        }
        cout << result << '\n';
    }
    
    return 0;
}
