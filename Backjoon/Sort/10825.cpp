//
//  10825.cpp
//  main
//
//  Created by wi_seong on 2022/03/04.
//

#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    vector<tuple<int, int, int, string>> students;
    while(n--) {
        int k, e, m;
        string name;
        cin >> name >> k >> e >> m;
        students.push_back({-k, e, -m, name});
    }
    sort(students.begin(), students.end());
    for(auto s : students)
        cout << get<3>(s) << '\n';
    return 0;
}
