//
//  main.cpp
//  9663
//
//  Created by wi_seong on 2022/02/08.
//

#include <iostream>

using namespace std;
int n;
int cnt = 0;
bool isused1[40];
bool isused2[40];
bool isused3[40];

void func(int cur) {
    if(n == cur) {
        cnt++;
        return;
    }
    for(int i = 0; i < n; i++) {
        if(isused1[i] || isused2[i+cur] || isused3[cur-i+n-1]) continue;
        isused1[i] = 1;
        isused2[i+cur] = 1;
        isused3[cur-i+n-1] = 1;
        func(cur+1);
        isused1[i] = 0;
        isused2[i+cur] = 0;
        isused3[cur-i+n-1] = 0;
    }
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    cin >> n;
    func(0);
    cout << cnt;
    return 0;
}
