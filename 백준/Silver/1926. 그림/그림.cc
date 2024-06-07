#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	int map[500][500];
	int dy[] = { 0, 1, 0, -1 };
	int dx[] = { 1, 0, -1, 0 };
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			map[i][j] *= -1;
		}
	}

	queue<pii> q;
	int count = 0;
	int size = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] >= 0) continue;
			count += 1;
			q.push({ i, j });
			map[i][j] = count;
			int subsize = 0;
			while (!q.empty())
			{
				int y = q.front().first, x = q.front().second;
				subsize += 1;
				q.pop();
				for (int k = 0; k < 4; k++)
				{
					int ny = y + dy[k], nx = x + dx[k];
					if (ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
					if (map[ny][nx] >= 0)continue;
					q.push({ ny, nx });
					map[ny][nx] = count;
				}
			}
			if (subsize > size) size = subsize;
		}
	}
	cout << count << "\n" << size;
	return 0;
}