//
//  1759.cpp
//  main
//
//  Created by wi_seong on 2022/02/28.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n, m, cnt1, cnt2;
char ch[17];
int arr[17];
bool isused[17];

bool chk(char ch) {return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';}
void solve(int k, int st) {
    if(k == n && cnt1 > 0 && cnt2 > 1) {
        for(int i = 0; i < n; i++)
            cout << ch[arr[i]];
        cout << '\n';
        return;
    }
    for(int i = st; i < m; i++) {
        if(!isused[i]) {
            bool state = chk(ch[i]);
            arr[k] = i;
            isused[i] = 1;
            if(state) cnt1++;
            else cnt2++;
            solve(k + 1, i + 1);
            if(state) cnt1--;
            else cnt2--;
            isused[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> ch[i];
    sort(ch, ch + m);
    solve(0, 0);
    
    return 0;
}
