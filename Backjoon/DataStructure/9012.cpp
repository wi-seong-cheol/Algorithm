//
//  main.cpp
//  9012
//
//  Created by wi_seong on 2022/01/02.
//

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    int depth;
    while(N--) {
        depth = 0;
        string str; cin >> str;
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '(') {
                depth++;
            } else {
                depth--;
                if(depth < 0) {
                    break;
                }
            }
        }
        if(depth == 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
