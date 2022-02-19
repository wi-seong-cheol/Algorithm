//
//  3273.cpp
//  main
//
//  Created by wi_seong on 2022/02/20.
//

#include <iostream>
#include <algorithm>

using namespace std;
bool arr[2000001];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        arr[t] = 1;
    }
    int x; cin >> x;
    int res = 0;
    for(int i = 1; i < (x+1)/2; i++)
        if(arr[i] && arr[x-i]) res++;
    cout << res;
    
    return 0;
}
