//
//  5430.cpp
//  main
//
//  Created by wi_seong on 2022/02/22.
//

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

void print_result(deque<int> &d) {
    cout << '[';
    for(int i = 0; i < d.size(); i++) {
        cout << d[i];
        if(i + 1 != d.size()) cout << ',';
    }
    cout << ']' << '\n';
}

void parse(string &tmp, deque<int> &d) {
    int cur = 0;
    for(int i = 1; i+1 < tmp.size(); i++)
    {
        if(tmp[i] == ','){
            d.push_back(cur);
            cur = 0;
        }
        else{
            cur = 10 * cur + (tmp[i] - '0');
        }
    }
    if(cur != 0)
        d.push_back(cur);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        string tmp, op;
        deque<int> d;
        int rev = 0;
        int n;
        bool isWrong = false;
        
        cin >> op;
        cin >> n;
        cin >> tmp;
        
        parse(tmp, d);
        for(auto p : op) {
            if(p == 'R') {
                rev = 1 - rev;
            } else if(p == 'D') {
                if(d.empty()) {
                    isWrong = true;
                    break;
                }
                if(rev) d.pop_back();
                else d.pop_front();
            }
        }
        if(isWrong) {
            cout << "error" << '\n';
        } else {
            if(rev) reverse(d.begin(), d.end());
            print_result(d);
        }
    }
    
    return 0;
}
