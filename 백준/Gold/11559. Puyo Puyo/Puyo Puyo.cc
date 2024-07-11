#include <iostream>
#include <queue>
using namespace std;

char map[12][7];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
struct puyo
{
	int y, x;
	char c;
	puyo(int y, int x, char c):y(y),x(x),c(c){}
	puyo(const puyo& other):y(other.y), x(other.x), c(other.c){}
};
bool check()
{
	bool visited[12][6] = { false };
	bool flag = false;
	for (int i = 0; i < 12; i++)
	{
		for(int j = 0; j < 6; j++)
		{ 
			if (visited[i][j] || map[i][j] == '.') continue;
			int count;
			visited[i][j] = true;
			queue<puyo> q, backup;
			q.emplace(i, j, map[i][j]);
			while (!q.empty())
			{
				puyo p = q.front(); q.pop();
				backup.emplace(p);
				for (int k = 0; k < 4; k++)
				{
					int y = p.y + dy[k], x = p.x + dx[k];
					if (y < 0 || y >= 12 || x < 0 || x >= 6 || visited[y][x] || map[y][x] != p.c) continue;
					visited[y][x] = true;
					q.emplace(y, x, p.c);
				}
			}
			if (backup.size() < 4) continue;
			flag = true;
			while (!backup.empty())
			{
				map[backup.front().y][backup.front().x] = '.';
				backup.pop();
			}
		}
	}
	if (flag)
	{
		for (int j = 0; j < 6; j++)
		{
			int last = -1;
			for (int i = 11; i >= 0; i--)
			{
				if (last == -1 && map[i][j] == '.') last = i;
				if (last >= 0 && map[i][j] != '.')
				{
					map[last--][j] = map[i][j];
					map[i][j] = '.';
				}
			}
		}
	}
	return flag;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 12; i++)
		cin >> map[i];

	int answer = 0;
	while (check()) answer += 1;
	cout << answer;
	
	return 0;
}