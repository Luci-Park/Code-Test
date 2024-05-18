#include <iostream>
using namespace std;
int n, h;
int map[10][30];
bool check()
{
	for (int i = 0; i < n; i++)
	{
		int ladder = i;
		for (int j = 0; j < h; j++)
		{
			if (map[ladder][j]) ladder += 1;
			else if (ladder > 0 && map[ladder - 1][j]) ladder -= 1;
		}
		if (ladder != i) return false;
	}
	return true;
}
int dfs(int depth = 0, int y = 0, int x = 0)
{
	if (check()) return depth;
	if (depth == 3) return -1;
	int min = 4;
	for (int i = y; i < n - 1; i++)
	{
		int j = (i == y) ? x : 0;
		for (; j < h; j++)
		{
			if (map[i][j]) continue;
			map[i][j] = 1;
			int answer = dfs(depth + 1, i, j + 1);
			if (answer > 0 && answer < min) min = answer;
			map[i][j] = 0;
		}
	}
	if (min == 4) return -1;
	return min;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		map[b - 1][a - 1] = 1;
	}
	cout << dfs();

	
	return 0;
}