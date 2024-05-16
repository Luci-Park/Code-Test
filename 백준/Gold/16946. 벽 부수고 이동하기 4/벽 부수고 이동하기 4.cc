#include <iostream>
#include <queue>
using namespace std;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int map[1000][1000];
bool visited[1000][1000] = { false, };
int n, m;
queue<pair<int, int>> q, wq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c; cin >> c;
			map[i][j] = c - '0';
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] || visited[i][j]) continue;
			visited[i][j] = true;
			q.push({ i, j });
			int answer = 0;
			while (!q.empty())
			{
				int y = q.front().first, x = q.front().second; q.pop();
				if (map[y][x]) { wq.push({ y, x }); continue; }
				answer += 1;
				for (int k = 0; k < 4; k++)
				{
					int ny = y + dy[k], nx = x + dx[k];
					if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
					if (visited[ny][nx]) continue;
					visited[ny][nx] = true;
					q.push({ ny, nx });
				}
			}
			while (!wq.empty())
			{
				int y = wq.front().first, x = wq.front().second; wq.pop();
				visited[y][x] = false;
				map[y][x] += answer;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << map[i][j] % 10;
		}
		cout << "\n";
	}

	return 0;
}