#include <iostream>
#include <vector>
using namespace std;

const int dy[4] = { -1, 0 , 1, 0 };
const int dx[4] = { 0 , 1, 0, -1 };
int N, M;
vector<vector<int>>board;
vector<vector<bool>> visited;
int ans = 0;

bool isValid(int y, int x) {
    if (0 <= y && y < N && 0 <= x && x < M) return true;
    return false;
}

void dfs(int y, int x, int sum, int depth) {
    if (depth == 4) {
        ans = max(sum, ans);
        return;
    }
    if (!isValid(y, x) || visited[y][x]) return;
    sum += board[y][x];
    visited[y][x] = true;
    for (int i = 0; i < 4; ++i) {
        int ty = y + dy[i], tx = x + dx[i];
        dfs(ty, tx, sum, depth + 1);
    }
    visited[y][x] = false;
}

void CheckUp(int y, int x) {
    int diry[4][4] = { {0, 0, -1, 0}, {0, 0, 1, 0}, {0, 1, 1, 2}, {0, 1, 1, 2} }; 
    int dirx[4][4] = { {0, 1, 1, 2}, {0, 1, 1, 2}, {0, 0, 1, 0}, {0, 0, -1, 0} };
    for (int i = 0; i < 4; i++) {
        int sum = 0;
        bool flag = true;
        for (int j = 0; j < 4; j++) {
            int ty = y + diry[i][j]; int tx = x + dirx[i][j];
            if (!isValid(ty, tx)) {
                flag = false; break; 
            }
            sum += board[ty][tx];
        }
        if (flag) {
            ans = max(sum, ans);
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    board = vector<vector<int>>(N, vector<int>(M));
    visited = vector<vector<bool>>(N, vector<bool>(M, false));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            dfs(i, j, 0, 0);//solves all except ㅏㅓㅗㅜ
            CheckUp(i, j);
        }
    }
    cout << ans;
    return 0;
}
