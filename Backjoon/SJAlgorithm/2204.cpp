//
//  main.cpp
//  2204
//
//  Created by wi_seong on 2022/02/06.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    for(int i = 0; i < a.size(); i++) {
        if(a[i] >= 'a' && a[i] <= 'z') {
            a[i] -= 32;
        }
    }
    
    for(int i = 0; i < b.size(); i++) {
        if(b[i] >= 'a' && b[i] <= 'z') {
            b[i] -= 32;
        }
    }
    if(a.compare(b) > 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    while(1) {
        int N; cin >> N;
        getchar();
        if(!N) break;
        
        vector<string> v(N);
        for(int i = 0; i < N; i++) {
            string s; cin >> s;
            v[i] = s;
        }
        sort(v.begin(), v.end(), compare);
        cout << v[0] << '\n';
    }
    
    return 0;
}
