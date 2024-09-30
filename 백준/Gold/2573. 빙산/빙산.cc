#include <iostream>
#include <queue>

using namespace std;
using pp = pair<int, int>;

int map[300][300];
bool visited[300][300] = { 0 };

int N, M;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
queue<pp> ice, water;

bool isValid(int y, int x)
{
	return 0 <= y && y < N && 0 <= x && x < M;
}

int numberOfArea()
{
	int count = 0;
	bool v[300][300] = { 0 };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!map[i][j] || v[i][j]) continue;
			queue<pp> q;
			q.push({ i, j });
			v[i][j] = true;
			count += 1;
			while (!q.empty())
			{
				int y = q.front().first, x = q.front().second; q.pop();
				for (int k = 0; k < 4; k++)
				{
					int ny = y + dy[k], nx = x + dx[k];
					if (!isValid(ny, nx)) continue;
					if (!map[ny][nx] || v[ny][nx]) continue;
					v[ny][nx] = true;
					q.push({ ny, nx });
				}
			}
		}
	}
	return count;
}

bool meltIce()
{
	while (!water.empty())
	{
		int y = water.front().first, x = water.front().second;
		water.pop();
		for (int k = 0; k < 4; k++)
		{
			int ny = y + dy[k], nx = x + dx[k];
			if (!isValid(ny, nx)) continue;
			if (!map[ny][nx] || visited[ny][nx]) continue;
			visited[ny][nx] = true;
			ice.push({ ny, nx });
		}
	}

	int count = ice.size();
	bool flag = false;
	queue<pp> melted;
	while (count--)
	{
		pp i = ice.front(); ice.pop();
		int c = 0;
		for (int k = 0; k < 4; k++)
		{
			int ny = i.first + dy[k], nx = i.second + dx[k];
			if (!isValid(ny, nx)) continue;
			if (map[ny][nx]) continue;
			c++;
		}
		if (map[i.first][i.second] - c <= 0) melted.push(i);
		else
		{
			ice.push(i);
			map[i.first][i.second] -= c;
		}
	}
	flag = melted.size();

	while (!melted.empty())
	{
		pp i = melted.front();
		melted.pop();
		map[i.first][i.second] = 0;
		water.push(i);
	}

	return flag;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
				water.push({ i, j });
		}
	}
	
	int year = 0;
	bool check = true;

	while (1)
	{
		if (check)
		{
			int piece = numberOfArea();
			if (piece == 0)
			{
				year = 0;
				break;
			}
			else if (piece > 1)
			{
				break;
			}
		}
		check = meltIce();
		year += 1;
	}

	cout << year;
	return 0;
}