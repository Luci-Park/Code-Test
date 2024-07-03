#include <iostream>
#include <queue>
using namespace std;

int rects[100][100] = { 0 };
int dy[] = { 0, -1, 0, 1 };
int dx[] = { 1, 0, -1, 0 };
priority_queue<int> numbers;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int m, n, k;
	cin >> m >> n >> k;
	while (k--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int i = b; i < d; i++)
			for (int j = a; j < c; j++)
				rects[i][j] = -1;
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (rects[i][j]) continue;
			queue<pair<int, int>> q;
			int count = 0;
			q.push({ i, j });
			rects[i][j] = 1;
			while (!q.empty())
			{
				auto p = q.front(); q.pop();
				count += 1;
				for (k = 0; k < 4; k++)
				{
					int ny = p.first + dy[k], nx = p.second + dx[k];
					if (ny < 0 || ny >= m || nx < 0 || nx >= n || rects[ny][nx] != 0) continue;
					q.push({ ny, nx });
					rects[ny][nx] = 1;
				}
			}
			if (count > 0) numbers.push(-count);
		}
	}

	cout << numbers.size() << "\n";
	while (!numbers.empty())
	{
		cout << -numbers.top() << " ";
		numbers.pop();
	}

	return 0;
}