#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int room[50][50];
    int dy[]{ -1, 0, 1, 0 };
    int dx[]{ 0, 1, 0, -1 };
    int n, m, r, c, d;
    cin >> n >> m >> r >> c >> d;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> room[i][j];

    int count = 0;
    while (true)
    {
        if (room[r][c] == 0)
        {
            room[r][c] = 2;
            count++;
        }
        bool moved = false;
        for (int i = 1; i <= 4; i++)
        {
            int nd = (d - i + 4) % 4;
            int nr = r + dy[nd], nc = c + dx[nd];
            if (room[nr][nc] != 0) continue;
            moved = true;
            r = nr; c = nc; d = nd;
            break;
        }
        if (moved) continue;
        int nd = (d + 2) % 4;
        int nr = r + dy[nd], nc = c + dx[nd];
        if (room[nr][nc] == 1) break;
        r = nr; c = nc;
    }
    cout << count;
    return 0;
}
