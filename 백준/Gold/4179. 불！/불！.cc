#include <iostream>
#include <queue>
using namespace std;

char m[1000][1000];
int visit[1000][1000];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int R, C;

bool isEdge(int y, int x)
{
	return y == 0 || x == 0 || y == R - 1 || x == C - 1;
}

int answer()
{
	cin >> R >> C;
	queue<pair<int, int>> p, np, f, nf;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> m[i][j];
			visit[i][j] = -1;
			if (m[i][j] == 'F') f.push({ i, j });
			else if (m[i][j] == 'J') { p.push({ i, j }); visit[i][j] = 0; m[i][j] = '.'; }
		}
	}

	while (true)
	{
		while (!p.empty())
		{
			int y = p.front().first, x = p.front().second;
			p.pop();
			if (m[y][x] == 'F') continue;
			if (isEdge(y, x)) return visit[y][x] + 1;
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i], nx = x + dx[i];
				if (ny < 0 || ny >= R || nx < 0 || nx >= C || visit[ny][nx] >= 0|| m[ny][nx] != '.') continue;
				np.push({ ny, nx });
				visit[ny][nx] = visit[y][x] + 1;
			}
		}
		while (!f.empty())
		{
			int y = f.front().first, x = f.front().second;
			f.pop();
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i], nx = x + dx[i];
				if (ny < 0 || ny >= R || nx < 0 || nx >= C || m[ny][nx] != '.') continue;
				m[ny][nx] = 'F';
				nf.push({ ny, nx });
			}
		}
		if (np.empty()) return -1;
		while (!np.empty()) { p.push(np.front()); np.pop(); }
		while (!nf.empty()) { f.push(nf.front()); nf.pop(); }
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int ans = answer();
	if (ans >= 0) cout << ans;
	else cout << "IMPOSSIBLE";

	return 0;
}