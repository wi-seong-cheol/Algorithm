//
//  main.cpp
//  20327
//
//  Created by wi_seong on 2022/01/04.
//

#include <iostream>
#include <math.h>
#include <queue>
#include <cstring>

using namespace std;

int N, R, range;
int mat[130][130];
int mat2[130][130];

void cal_1(int len) {
    int a, b;
    int cnt = 0;

    for(int i = 0; i < range; i+=len) {
        for(int j = 0; j < range; j+=len) {
            a = i + len;
            b = j + len;
            for(int x = i; x < a; x++) {
                for(int y = j; y < b; y++) {
                    mat2[a-1-x + len*cnt][y] = mat[x][y];
                }
            }
        }
        cnt++;
    }
    memcpy(mat, mat2, sizeof(mat2));
}

void cal_2(int len) {
    int a, b;
    int cnt = 0;

    for(int i = 0; i < range; i+=len) {
        for(int j = 0; j < range; j+=len) {
            a = i + len;
            b = j + len;
            for(int x = i; x < a; x++) {
                for(int y = j; y < b; y++) {
                    mat2[x][b-1-y+len*cnt] = mat[x][y];
                }
            }
            cnt++;
        }
        cnt = 0;
    }
    memcpy(mat, mat2, sizeof(mat2));
}

void cal_3(int len) {
    int a, b;
    int gap_c=0, gap_r=0;
    int cnt = 0;

    for(int i = 0; i < range; i+=len) {
        for(int j = 0; j < range; j+=len) {
            a = i + len;
            b = j + len;
            for(int x = i; x < a; x++) {
                for(int y = j; y < b; y++) {
                    mat2[y-len*gap_r+len*cnt][a-1-x+len*gap_c] = mat[x][y];
                }
            }
            gap_c++;
            gap_r++;
        }
        cnt++;
        gap_c = 0;
        gap_r = 0;
    }
    memcpy(mat, mat2, sizeof(mat2));
}

void cal_4(int len) {
    int a, b;
    int gap_c=0, gap_r=0;
    int cnt = 0;
    
    for(int i = 0; i < range; i+=len) {
        for(int j = 0; j < range; j+=len) {
            a = i + len;
            b = j + len;
            for(int x = i; x < a; x++) {
                for(int y = j; y < b; y++) {
                    mat2[b-1-y + len*gap_r][x + len*gap_c - len*cnt] = mat[x][y];
                }
            }
            gap_c++;
        }
        cnt++;
        gap_r++;
        gap_c = 0;
    }
    memcpy(mat, mat2, sizeof(mat2));
}

void cal_5(int len) {
    cal_1(range);
    cal_1(len);
}

void cal_6(int len) {
    cal_2(range);
    cal_2(len);
}

void cal_7(int len) {
    cal_3(range);
    cal_4(len);
}

void cal_8(int len) {
    cal_4(range);
    cal_3(len);
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> R;
    range = 1 << N;
    
    for(int i = 0; i < range; i++) {
        for(int j = 0; j < range; j++) {
            int x; cin >> x;
            mat[i][j] = x;
        }
    }
    
    while(R--) {
        int a, b; cin >> a >> b;
        int len = 1 << b;
        
        if (len == 0) {
            continue;
        } else if (a == 1) {
            cal_1(len);
        } else if (a == 2) {
            cal_2(len);
        } else if (a == 3) {
            cal_3(len);
        } else if (a == 4) {
            cal_4(len);
        } else if (a == 5) {
            cal_5(len);
        } else if (a == 6) {
            cal_6(len);
        } else if (a == 7) {
            cal_7(len);
        } else if (a == 8) {
            cal_8(len);
        }
    }
    
    for(int i = 0; i < range; i++) {
        for(int j = 0; j < range; j++) {
            cout << mat[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
