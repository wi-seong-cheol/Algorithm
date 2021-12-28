//
//  main.cpp
//  22942
//
//  Created by wi_seong on 2021/12/28.
//

#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct Info { int pos, is_open, type; };

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<Info> v;
    
    for(int i = 0; i < N; i++) {
        int x, r; cin >> x >> r;
        v.push_back({x - r, 1, i});
        v.push_back({x + r, 0, i});
    }
    
    sort(v.begin(), v.end(), [](const Info& a, const Info& b) {
        return a.pos < b.pos;
    });
    
    auto Sol = [&]() -> bool {
        for(int i = 1; i < v.size(); i++) {
            if(v[i - 1].pos == v[i].pos)
                return 0;
        }
        stack<int> S;
        for(const auto& [_, is_open, type] : v) {
            if(is_open) S.push(type);
            else if(S.top() != type) return 0;
            else S.pop();
        }
        return 1;
    };
    
    cout << (Sol() ? "YES" : "NO") << '\n';
    return 0;
}

