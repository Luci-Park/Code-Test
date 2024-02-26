#include <iostream>
#include <queue>
using namespace std;
int map[8][8];
pair<int, int> walls[64];
int wallCnt;
pair<int, int> virus[64];
int virusCnt;
int n, m;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0};

int bfs()
{
	int cnt = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < virusCnt; i++)
		q.push(virus[i]);

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < n && 0 <= nx && nx < m 
				&& map[ny][nx] == 0)
			{
				map[ny][nx] = -2;
				q.push(make_pair(ny, nx));
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
				cnt++;
			if (map[i][j] == -2)
				map[i][j] = 0;
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	wallCnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
			{
				walls[wallCnt++] = make_pair(i, j);
			}
			if (map[i][j] == 2)
			{
				virus[virusCnt++] = make_pair(i, j);
			}
		}
	}
	int maxRoom = 0;
	for (int i = 0; i < wallCnt - 2; i++)
	{
		map[walls[i].first][walls[i].second] = 1;
		for (int j = i + 1; j < wallCnt - 1; j++)
		{
			map[walls[j].first][walls[j].second] = 1;
			for (int k = j + 1; k < wallCnt; k++)
			{
				map[walls[k].first][walls[k].second] = 1;
				int rslt = bfs();
				if (rslt > maxRoom)
					maxRoom = rslt;
				map[walls[k].first][walls[k].second] = 0;
			}
			map[walls[j].first][walls[j].second] = 0;
		}
		map[walls[i].first][walls[i].second] = 0;
	}
	cout << maxRoom;
}