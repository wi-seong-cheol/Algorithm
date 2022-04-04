//
//  17085.cpp
//  main
//
//  Created by wi_seong on 2022/04/03.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
char a[16][16];
int s[256];

bool OOB(int a, int bound) { return a <= 0 || a > bound; }
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    int pos = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] != '#') continue;
            int size = 1;
            for(int k = 1; ; k++) {
                if(OOB(j - k, m) || OOB(j + k, m) || OOB(i - k, n) || OOB(i + k, n)) break;
                if(a[i][j - k] == '#' && a[i][j + k] == '#' && a[i - k][j] == '#' && a[i + k][j] == '#') size += 4;
                else break;
            }
            s[pos++] = size;
        }
    }
    sort(s, s + pos);
    cout << s[pos - 1];
    cout << s[pos - 2];
    
    return 0;
}
/*
 6 12
 ........#...
 ...#....#...
 ...#.#######
 #######.#...
 ##.##...#...
 ...#........
 */

