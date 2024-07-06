#include <iostream>
#include <queue>
using namespace std;
int map[100][100];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int n;
queue<pair<int, int>> islands[10000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			map[i][j] *= -1;
		}
	}
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] >= 0) continue;
			count += 1;
			queue<pair<int, int>> q;
			q.push({ i, j });
			map[i][j] = count;
			while (!q.empty())
			{
				int y = q.front().first, x = q.front().second;
				q.pop();
				bool isSide = false;
				for (int k = 0; k < 4; k++)
				{
					int ny = y + dy[k], nx = x + dx[k];
					if (ny < 0 || ny >= n || nx < 0 || nx >= n || map[ny][nx] == count) continue;
					if (map[ny][nx] == 0) { isSide = true; continue; }
					map[ny][nx] = count;
					q.push({ ny, nx });
				}
				if (isSide)
					islands[count - 1].push({ y, x });
			}
		}
	}
	int minNum = 10000;
	for (int i = 0; i < count; i++)
	{
		int visited[100][100] = { 0 };
		while (!islands[i].empty())
		{
			int y = islands[i].front().first, x = islands[i].front().second;
			islands[i].pop();
			if (map[y][x] != 0 && map[y][x] != i + 1)
			{
				minNum = min(minNum, visited[y][x]);
				break;
			}
			for (int k = 0; k < 4; k++)
			{
				int ny = y + dy[k], nx = x + dx[k];
				if (ny < 0 || ny >= n || nx < 0 || nx >= n 
					|| map[ny][nx] == i + 1 || visited[ny][nx]) continue;
				visited[ny][nx] = visited[y][x] + 1;
				islands[i].push({ny, nx});
			}
		}
	}
	cout << minNum - 1;
    return 0;
}