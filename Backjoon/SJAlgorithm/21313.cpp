//
//  main.cpp
//  21313
//
//  Created by wi_seong on 2022/01/04.
//

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    bool odd = false;
    if(N%2) {
        odd = true;
        N--;
    }
    while(N--) {
        if(N%2) {
            cout << "1 ";
        } else {
            cout << "2 ";
        }
    }
    if(odd) cout << "3";
    
    return 0;
}
