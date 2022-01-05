//
//  main.cpp
//  20327
//
//  Created by wi_seong on 2022/01/04.
//

#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

int N, R, s;
vector<vector<int>> v;

void cal_1(int l) {
    
}
int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> R;
    s = pow(2,N);
    v.resize(s, vector<int>(s, 0));
    
    for(int i = 0; i < s; i++) {
        for(int j = 0; j < s; j++) {
            int x; cin >> x;
            v[i][j] = x;
        }
    }
    
    while(R--) {
        int a, b; cin >> a, b;
        
        if (a == 0) {
            continue;
        } else if (a == 1) {
            cal_1(b);
        } else if (a == 2) {
            
        } else if (a == 3) {
            
        } else if (a == 4) {
            
        } else if (a == 5) {
            
        } else if (a == 6) {
            
        } else if (a == 7) {
            
        } else if (a == 8) {
            
        }
    }
    
    for(int i = 0; i < s; i++) {
        for(int j = 0; j < s; j++) {
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
