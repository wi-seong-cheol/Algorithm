//
//  main.cpp
//  Test
//
//  Created by wi_seong on 2022/01/11.
//

#include <iostream>
#include <ctime>

using namespace std;

int func1(int N) {
    int result = 0;
    
    for(int i = 3; i < N; i++) {
        if(i % 3 == 0 || i % 5 == 0) {
            result += i;
        }
    }
    return result;
}

int func2(int arr[], int N) {
    int ret = 0;
    
    for(int i = 0; i < N-1; i++) {
        for(int j = i + 1; j < N; j++) {
            if(arr[i] + arr[j] == 100)
                ret = 1;
        }
    }
    return ret;
}

int func3(int N) {
    for(int i = 0; i < N/2; i++) {
        if(i*i == N) {
            return 1;
        } else if(i*i > N) {
            break;
        }
    }
    return 0;
}

int func4(int N) {
    int val = 1;
    while(2*val <= N) val *= 2;
    return val;
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    clock_t start, finish;
    double duration;
    
    // func1
    /*
    cout << func1(16) << '\n';
    cout << func1(34567) << '\n';
    cout << func1(27639) << '\n';
    */
    
    // func2
    /*
    int arr[] = {4, 13, 63, 87};
    cout << func2(arr, 4) << '\n';
    */
     
    // func3
    /*
    cout << func3(9) << '\n';
    cout << func3(693953651) << '\n';
    cout << func3(756580036) << '\n';
    */
    
    
    // func4
    start = clock();
    cout << func4(5) << '\n';
    cout << func4(97615282) << '\n';
    cout << func4(1024) << '\n';
    /*
    */
    
    finish = clock();
    
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << duration << "초" << endl;
    
    return 0;
}
