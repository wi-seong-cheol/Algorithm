//
//  1253.cpp
//  main
//
//  Created by wi_seong on 2022/04/21.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int n;
int a[2001];
map<int,int> occur;
vector<int> add;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        occur[a[i]] += 1;
    }
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) continue;
        for(int j = i + 1; j < n; j++) {
            if(a[j] == 0) continue;
            add.push_back(a[i] + a[j]);
        }
    }
    sort(add.begin(), add.end());
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(binary_search(add.begin(), add.end(), a[i])) {
            cnt++;
            continue;
        }
        if(a[i] == 0) {
            if(occur[0] >= 3) {
                cnt++;
            }
            continue;
        }
        if(occur[0] >= 1 and occur[a[i]] >= 2) {
            cnt++;
        }
    }
    cout << cnt;
    
    return 0;
}
