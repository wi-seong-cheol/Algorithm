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

void cal_2(int l) {
    
}

void cal_3(int l) {
    
}

void cal_4(int l) {
    
}

void cal_5(int l) {
    
}

void cal_6(int l) {
    
}

void cal_7(int l) {
    
}

void cal_8(int l) {
    
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
        int a, b; cin >> a >> b;
        
        if (a == 0) {
            continue;
        } else if (a == 1) {
            cal_1(b);
        } else if (a == 2) {
            cal_2(b);
        } else if (a == 3) {
            cal_3(b);
        } else if (a == 4) {
            cal_4(b);
        } else if (a == 5) {
            cal_5(b);
        } else if (a == 6) {
            cal_6(b);
        } else if (a == 7) {
            cal_7(b);
        } else if (a == 8) {
            cal_8(b);
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
