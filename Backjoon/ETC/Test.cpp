//
//  main.cpp
//  Test
//
//  Created by wi_seong on 2022/01/11.
//

#include <bits/stdc++.h>
using namespace std;
string ltrim(const string &);
string rtrim(const string &);

vector<string> findSchedules(int workHours, int dayHours, string pattern) {
    bool pos[7];
    int n = 0;
    vector<string> v(7, 0);
    for(int i = 0; i < 7; i++) {
        if(pattern[i] >= '0' && pattern[i] <= '9') {
            pos[i] = true;
            n += pattern[i] - '0';
            v[i] = pattern[i];
        }
        else pos[i] = false;
    }
    for(int i = 0; i < 1111111 * dayHours + 1; i++) {
        
        int brute = i;
        for(int j = 0; j < 7; j++) {
            int n = brute % dayHours;
            brute /= dayHours;
            cout << brute << ' ';
        }
        cout << '\n';
    }
    return v;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string workHours_temp;
    getline(cin, workHours_temp);

    int workHours = stoi(ltrim(rtrim(workHours_temp)));

    string dayHours_temp;
    getline(cin, dayHours_temp);

    int dayHours = stoi(ltrim(rtrim(dayHours_temp)));

    string pattern;
    getline(cin, pattern);

    vector<string> result = findSchedules(workHours, dayHours, pattern);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

//    s.erase(
//        s.begin(),
//        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
//    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

//    s.erase(
//        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
//        s.end()
//    );

    return s;
}
