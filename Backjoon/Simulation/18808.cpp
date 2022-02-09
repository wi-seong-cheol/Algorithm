//
//  main.cpp
//  18808
//
//  Created by wi_seong on 2022/02/09.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n, m, k;
int note[42][42];
int paper[12][12];
int r, c;

bool pastable(int x, int y) {
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(note[x+i][y+j] == 1 && paper[i][j] == 1)
                return false;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(paper[i][j] == 1)
                note[x+i][y+j] = 1;
    return true;
}

void rotation(){
  int tmp[12][12];

  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
      tmp[i][j] = paper[i][j];

  for(int i = 0; i < c; i++)
    for(int j = 0; j < r; j++)
      paper[i][j] = tmp[r-1-j][i];

  swap(r, c);
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    cin >> n >> m >> k;
    while(k--) {
        cin >> r >> c;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                cin >> paper[i][j];
        
        for(int k = 0; k < 4; k++) {
            bool state = 0;
            for(int i = 0; i <= n - r; i++) {
                if(state) break;
                for(int j = 0; j <= m - c; j++) {
                    if(pastable(i, j)) {
                        state = 1;
                        break;
                    }
                }
            }
            if(state) break;
            rotation();
        }
    }
    
    int res = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            res += note[i][j];
    cout << res;
    return 0;
}
