#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dy[4] = { -1, 0 , 0, 1 };
const int dx[4] = { 0 , -1, 1, 0 };
int N;
int fishSize = 2;
int eatcnt = 0;
vector<vector<int>>board;

struct Fish {
    int y, x, dist;
};

bool isAOverB(int ya, int xa, int yb, int xb) {
    if (ya != yb) return ya < yb;
    return xa < xb;
}

bool isValid(int y, int x) {
    if (0 <= y && y < N && 0 <= x && x < N) return true;
    return false;
}

Fish GetClosestFish(int y, int x) {
    Fish fish({ N+1, N+1, INT16_MAX });
    vector<vector<int>> visited(N, vector<int>(N, -1));
    queue<pair<int, int>> q; 
    q.push(make_pair(y, x)); visited[y][x] = 0;
    while (!q.empty()) {
        int ny = q.front().first, nx = q.front().second; q.pop();
        for (int i = 0; i < 4; ++i) {
            int ty = ny + dy[i], tx = nx + dx[i];
            if (!isValid(ty, tx) || visited[ty][tx] >= 0|| board[ty][tx] > fishSize) continue;
            visited[ty][tx] = visited[ny][nx] + 1;
            q.push(make_pair(ty, tx));
            if (board[ty][tx] < fishSize && board[ty][tx] > 0 &&
                (visited[ty][tx] < fish.dist || 
                    (visited[ty][tx] == fish.dist && isAOverB(ty,tx,fish.y, fish.x)))) {
                fish.y = ty; fish.x = tx; fish.dist = visited[ty][tx];
            }
        }
    }
    return fish;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    board = vector<vector<int>>(N, vector<int>(N));
    int y, x;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                y = i; x = j; board[i][j] = -1;
            }
        }
    }
    Fish fish;
    int sec = 0;
    while ((fish = GetClosestFish(y, x)).dist != INT16_MAX) {
        y = fish.y; x = fish.x; eatcnt += 1; sec += fish.dist;
        if (eatcnt >= fishSize) { fishSize += 1; eatcnt = 0; }
        board[y][x] = -1;
    }
    cout << sec;
    return 0;
}
