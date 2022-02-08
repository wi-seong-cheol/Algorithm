//
//  main.cpp
//  17478
//
//  Created by wi_seong on 2022/02/08.
//

#include <iostream>

using namespace std;
int n;

void bar(const char* str, int stk) {
    for(int i = 0; i < stk; ++i) cout << "____";
    cout << str << '\n';
}
void func1(int cnt) {
    bar("\"재귀함수가 뭔가요?\"", cnt);
    if(cnt == n) bar("\"재귀함수는 자기 자신을 호출하는 함수라네\"", cnt);
    else {
        bar("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.", cnt);
        bar("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.", cnt);
        bar("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"", cnt);
        func1(cnt+1);
    }
    bar("라고 답변하였지.", cnt);
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin >> n;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << '\n';
    func1(0);
    
    return 0;
}
