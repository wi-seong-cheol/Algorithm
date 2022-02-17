//
//  main.cpp
//  Test
//
//  Created by wi_seong on 2022/01/11.
//

#include <bits/stdc++.h>

using namespace std;

void unordered_set_example() {
    unordered_set<int> s;
    s.insert(-10); s.insert(100); s.insert(15);
    s.insert(-10);
    cout << s.erase(100) << '\n';
    cout << s.erase(20) << '\n';
    if(s.find(15) != s.end()) cout << "15 in s\n";
    else cout << "15 not in s\n";
    cout << s.size() << '\n';
    cout << s.count(50) << '\n';
    for(auto e : s) cout << e << '\n';
    cout << '\n';
}

void unordered_multiset_example() {
    unordered_multiset<int> ms;
    ms.insert(-10); ms.insert(100); ms.insert(15);
    ms.insert(-10); ms.insert(15);
    cout << ms.size() << '\n';
    for(auto e : ms) cout << e << '\n';
    cout << '\n';
    cout << ms.erase(15) << '\n';
    ms.erase(ms.find(-10));
    ms.insert(100);
    cout << ms.count(100) << '\n';
}

void unordered_map_example() {
    unordered_map<string, int> m;
    m["hi"] = 123;
    m["bkd"] = 1000;
    m["gogo"] = 165;
    cout << m.size() << '\n';
    m["hi"] = -7;
    if(m.find("hi") != m.end()) cout << "hi in m\n";
    else cout << "hi not in m\n";
    m.erase("bkd");
    for(auto e : m)
        cout << e.first << ' ' << e.second << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cout << "unordered_set_example" << '\n';
    unordered_set_example();
    cout << "unordered_multiset_example" << '\n';
    unordered_multiset_example();
    cout << "unordered_map_example" << '\n';
    unordered_map_example();
    
    return 0;
}
