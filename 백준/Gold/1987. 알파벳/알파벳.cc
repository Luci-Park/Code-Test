#include <iostream>
#include <queue>
using namespace std;
bool visited[26];
char board[20][20];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int r, c;
int maxNum = 0;

void rec(int depth, int y, int x)
{
    if(y < 0 || r <= y || x < 0 || c <= x) return;
    if(visited[board[y][x] - 'A']) return;
    visited[board[y][x] - 'A'] = true;
    if(depth > maxNum)
        maxNum = depth;
    for(int i =0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        rec(depth + 1, ny, nx);
    }
    visited[board[y][x] - 'A'] = false;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    for(int i =0; i < r; ++i)
        for(int j =0; j < c; ++j)
            cin >> board[i][j];

    rec(1, 0, 0);
    cout << maxNum;
    return 0;
}