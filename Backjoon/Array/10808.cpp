//
//  10808.cpp
//  1158
//
//  Created by wi_seong on 2022/01/11.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    string S; cin >> S;
    int freq[26];
    fill(freq, freq + 26, 0);

    for(auto c : S) {
        freq[c-'a']++;
    }

    for(int i = 0; i < 26; i++)
        cout << freq[i] << ' ';

    return 0;
}
