//
//  main.cpp
//  10866
//
//  Created by wi_seong on 2022/01/03.
//

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    deque<int> q;
    
    while (t--) {
        string s; cin >> s;
        
        /*
         push_front X: 정수 X를 덱의 앞에 넣는다.
         push_back X: 정수 X를 덱의 뒤에 넣는다.
         pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
         pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
         size: 덱에 들어있는 정수의 개수를 출력한다.
         empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
         front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
         back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
         */
        if (s == "push_front") {
            int data; cin >> data;
            q.push_front(data);
        } else if (s == "push_back") {
            int data; cin >> data;
            q.push_back(data);
        } else if (s == "pop_front") {
            if (q.empty()) {
                cout << "-1" << '\n';
            } else {
                cout << q.front() << '\n';
                q.pop_front();
            }
        } else if (s == "pop_back") {
            if (q.empty()) {
                cout << "-1" << '\n';
            } else {
                cout << q.back() << '\n';
                q.pop_back();
            }
        } else if (s == "size") {
            cout << q.size() << '\n';
        } else if (s == "empty") {
            cout << q.empty() << '\n';
        } else if (s == "front") {
            if (q.empty()) {
                cout << "-1" << '\n';
            } else {
                cout << q.front() << '\n';
            }
        } else if (s == "back") {
            if (q.empty()) {
                cout << "-1" << '\n';
            } else {
                cout << q.back() << '\n';
            }
        }
    }
    
    return 0;
}
