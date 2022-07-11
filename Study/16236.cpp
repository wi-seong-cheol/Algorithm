//
//  16236.cpp
//  main
//
//  Created by wi_seong on 2022/10/04.
//

/*
 [Input]
 6
 5 4 3 2 3 4
 4 3 2 3 4 5
 3 2 9 5 6 6
 2 1 2 3 4 5
 3 2 1 6 5 4
 6 6 6 6 6 6
 
 [Output]
 60
 */
// 시간복잡도: O((NM) ^ 2)
// 최악시간: 20 ^ 4 = 160'000

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

#define X first
#define Y second

using namespace std;
const int INF = 0x7f7f7f7f;
const int SIZE = 21;

int result, n, eat, x, y;
int shark_size = 2;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int board[SIZE][SIZE];
int check[SIZE][SIZE];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    queue<pair<int, int>> Q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 9) {
                x = i;
                y = j;
            }
        }
    }
    while(1) {
        for(int i = 0; i < n; i++)
            fill(check[i], check[i] + n, -1);
        board[x][y] = 0;
        check[x][y] = 0;
        vector<pair<int, int>> fish;
        if(eat >= shark_size) {
            eat -= shark_size;
            shark_size++;
        }
        queue<pair<int, int>> Q;
        Q.push({x, y});
        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(OOB(nx, ny) || check[nx][ny] != -1) continue;
                if(shark_size < board[nx][ny]) continue;
                if(shark_size == board[nx][ny] || board[nx][ny] == 0) {
                    check[nx][ny] = check[cur.X][cur.Y] + 1;
                    Q.push({nx, ny});
                } else if(board[nx][ny] < shark_size && 0 < board[nx][ny]) {
                    check[nx][ny] = check[cur.X][cur.Y] + 1;
                    fish.push_back({nx, ny});
                    Q.push({nx, ny});
                }
            }
        }
        if(fish.size() == 0) {         // 먹을 수 있는 물고기가 없을 때
            cout << result << "\n";
            return 0;
        } else if(fish.size() == 1) {  // 먹을 수 있는 물고기가 1마리 일 때
            x = fish.front().X;
            y = fish.front().Y;
            board[x][y] = 0;
            eat++;
            result += check[x][y];
        } else {                        // 먹을 수 있는 물고기가 여러 마리 일 때
            int mindist = INF;
            for(auto& f : fish) {
                mindist = min(mindist, check[f.X][f.Y]);
            }
            vector<pair<int, int>> minfish;
            for (auto& f : fish) {
                if (mindist == check[f.X][f.Y]) {
                    minfish.push_back({f.X, f.Y});
                }
            }
            if(minfish.size() == 1) { // 최소 거리가 같은 물고기가 없을 때
                x = minfish.front().X;
                y = minfish.front().Y;
                result += check[x][y];
                board[x][y] = 0;
                eat++;
            } else {                    // 최소 거리가 같은 물고기가 여러 마리 일 때
                sort(minfish.begin(), minfish.end());
                x = minfish.front().X;
                y = minfish.front().Y;
                result += check[x][y];
                board[x][y] = 0;
                eat++;
            }
        }
    }

    return 0;
}
