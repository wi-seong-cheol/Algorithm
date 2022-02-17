//
//  1927.cpp
//  main
//
//  Created by wi_seong on 2022/02/17.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수

void push(int x){
    heap[++sz] = x;
    int idx = sz;
    while(idx != 1) {
        int par = idx/2;
        if(heap[par] <= heap[idx]) break;
        swap(heap[par], heap[idx]);
        idx = par;
    }
}

int top(){
    return heap[1];
}

void pop(){
    heap[1] = heap[sz--];
    int idx = 1;
    while(2*idx <= sz) {
        int lc = 2 * idx, rc = 2 * idx + 1;
        int min_child = lc;
        if(rc <= sz && heap[rc] < heap[lc])
            min_child = rc;
        if(heap[idx] <= heap[min_child]) break;
        swap(heap[idx], heap[min_child]);
        idx = min_child;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--) {
        int x; cin >> x;
        if(x == 0) {
            if(sz == 0) cout << 0 << '\n';
            else {
                cout << top() << '\n';
                pop();
            }
        } else {
            push(x);
        }
    }
    return 0;
}
