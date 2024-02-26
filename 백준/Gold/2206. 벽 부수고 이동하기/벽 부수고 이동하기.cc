#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;

int main()
{
    typedef struct move {
        int y;
        int x;
        bool wall;
        int length;
    }move;

    int N, M;
    int dy[4] = { 0, 1, 0, -1 };
    int dx[4] = { 1, 0, -1, 0 };
    int map[MAX][MAX];
    bool visited[MAX][MAX][2] = { {{0}}, };

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    visited[0][0][0] = true;
    queue<move> q; q.push({ 0, 0, false, 1 });

    while (!q.empty()) {
        move t = q.front(); q.pop();
        if (t.y == N - 1 && t.x == M - 1) {
            printf("%d", t.length);
            return 0;
        }
        for (int i = 0; i < 4; ++i) {
            int y = t.y + dy[i], x = t.x + dx[i];
            if (y < 0 || y >= N || x < 0 || x >= M) continue;
            if (!map[y][x] && !visited[y][x][t.wall]) {
                q.push({ y, x, t.wall, t.length + 1 });
                visited[y][x][t.wall] = true;
            }
            else if (map[y][x] && !t.wall && !visited[y][x][1]) {
                q.push({ y, x, 1, t.length + 1 });
                visited[y][x][1] = true;
            }
        }
    }
    printf("-1");
    return 0;
}