//
//  main.cpp
//  1406
//
//  Created by wi_seong on 2022/01/15.
//

#include <iostream>
#include <list>
// 연결리스트
//const int MX = 1000005;
//char dat[MX];
//int pre[MX], nxt[MX];
//int unused = 1;
//
//using namespace std;
//
//void insert(int addr, char num) {
//    dat[unused] = num;
//    pre[unused] = addr;
//    nxt[unused] = nxt[addr];
//    if(nxt[addr] != -1) pre[nxt[addr]] = unused;
//    nxt[addr] = unused;
//    unused++;
//}
//
//void erase(int addr) {
//    nxt[pre[addr]] = nxt[addr];
//    if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
//}
//
//void traverse() {
//    int cur = nxt[0];
//    while (cur != -1) {
//        cout << dat[cur];
//        cur = nxt[cur];
//    }
//}
//
//void solution() {
//    string s; cin >> s;
//    int cursor = 0;
//    for(int i = 0; i < s.length(); i++) {
//        insert(i, s[i]);
//        cursor++;
//    }
//    int tc; cin >> tc;
//    while (tc--) {
//        char ch; cin >> ch;
//        if (ch == 'L') {
//            if (pre[cursor] != -1) cursor = pre[cursor];
//        } else if (ch == 'D') {
//            if (nxt[cursor] != -1) cursor = nxt[cursor];
//        } else if (ch == 'B') {
//            if (pre[cursor] != -1) {
//                erase(cursor);
//                cursor = pre[cursor];
//            }
//        } else if (ch == 'P') {
//            char a; cin >> a;
//            insert(cursor, a);
//            cursor = nxt[cursor];
//        }
//    }
//
//    traverse();
//}
//int main() {
//    ios::sync_with_stdio(NULL);
//    cin.tie(NULL); cout.tie(NULL);
//
//    fill(pre, pre+MX, -1);
//    fill(nxt, nxt+MX, -1);
//
//    solution();
//
//    return 0;
//}

// STL
using namespace std;

void solution() {
    string s; cin  >> s;
    list<char> L;
    for(auto ch: s) L.push_back(ch);
    auto cursor = L.end();
    int tc; cin >> tc;
    while (tc--) {
        char op; cin >> op;
        if (op == 'L') {
            if(cursor != L.begin()) cursor--;
        } else if (op == 'D') {
            if(cursor != L.end()) cursor++;
        } else if (op == 'B') {
            if(cursor != L.begin()) {
                cursor--;
                cursor = L.erase(cursor);
            }
        } else if (op == 'P') {
            char a; cin >> a;
            L.insert(cursor, a);
        }
    }
    
    for(auto c: L) cout << c;
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    solution();
    
    return 0;
}
