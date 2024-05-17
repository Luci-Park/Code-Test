#include <iostream>
using namespace std;
int n, m;
int map[8][8];
pair<int, int>cctv[8];
int cctvCount = 0;
int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };

void fillDir(int y, int x, int dir, int idx)
{
	int ny = y + dy[dir], nx = x + dx[dir];
	while (0 <= ny && ny < n && 0 <= nx && nx < m && map[ny][nx] != 6)
	{
		if(map[ny][nx] == 0) map[ny][nx] = idx;
		ny += dy[dir];
		nx += dx[dir];
	}
}
void eraseDir(int y, int x, int dir, int idx)
{
	int ny = y + dy[dir], nx = x + dx[dir];
	while (0 <= ny && ny < n && 0 <= nx && nx < m && map[ny][nx] != 6)
	{
		if (map[ny][nx] == idx) map[ny][nx] = 0;
		ny += dy[dir];
		nx += dx[dir];
	}
}

int dfs(int depth)
{
	if (depth == cctvCount)
	{
		int count = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!map[i][j]) count += 1;
		return count;
	}
	int y = cctv[depth].first, x = cctv[depth].second;
	int minNum = 64;
	int idx = -depth - 1;
	switch (map[y][x])
	{
	case 1:
		for (int i = 0; i < 4; i++)
		{
			fillDir(y, x, i, idx);
			minNum = min(minNum, dfs(depth + 1));
			eraseDir(y, x, i, idx);
		}
		break;
	case 2:
		for (int i = 0; i < 2; i++)
		{
			fillDir(y, x, i, idx );
			fillDir(y, x, i + 2, idx);
			minNum = min(minNum, dfs(depth + 1));
			eraseDir(y, x, i, idx);
			eraseDir(y, x, i + 2, idx);
		}
		break;
	case 3:
		for (int i = 0; i < 4; i++)
		{
			fillDir(y, x, i, idx);
			fillDir(y, x, (i + 1) % 4, idx);
			minNum = min(minNum, dfs(depth + 1));
			eraseDir(y, x, i, idx);
			eraseDir(y, x, (i + 1) % 4, idx);
		}
		break;
	case 4:
		for (int i = 0; i < 4; i++)
		{
			fillDir(y, x, i, idx);
			fillDir(y, x, (i + 1) % 4, idx);
			fillDir(y, x, (i + 2) % 4, idx);
			minNum = min(minNum, dfs(depth + 1));
			eraseDir(y, x, i, idx);
			eraseDir(y, x, (i + 1) % 4, idx);
			eraseDir(y, x, (i + 2) % 4, idx);
		}
		break;
	case 5:
		for (int i = 0; i < 4; i++)
			fillDir(y, x, i, idx);
		minNum = min(minNum, dfs(depth + 1));
		for (int i = 0; i < 4; i++)
			eraseDir(y, x, i, idx);
		break;
	}
	return minNum;
}
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
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] < 6) cctv[cctvCount++] = { i, j };
		}
	}

	cout << dfs(0);

	return 0;
}