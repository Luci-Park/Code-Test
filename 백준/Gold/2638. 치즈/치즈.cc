#include <iostream>
#include <list>
#include <set>
#define EMPTY -1
#define INSIDE 0
using namespace std;
int board[100][100];
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1 ,0 };
int n, m;
list<pair<int, int>> cheese;
void CheckForEmpty(int y, int x)
{
	if (y < 0 || y >= n || x < 0 || x >= m) return;
	if (board[y][x] != INSIDE) return;
	board[y][x] = EMPTY;
	for (int k = 0; k < 4; k++)
	{
		int ny = y + dy[k], nx = x + dx[k];
		CheckForEmpty(ny, nx);
	}
}
void Melt()
{
	list<pair<int, int>> melted;
	for (auto iter = cheese.begin(); iter != cheese.end();)
	{
		int count = 0;
		for (int i = 0; i < 4; i++)
		{
			int ny = iter->first + dy[i], nx = iter->second + dx[i];
			if (board[ny][nx] == EMPTY) ++count;
		}
		if (count >= 2)
		{
			melted.push_back(*iter);
			iter = cheese.erase(iter);
		}
		else
		{
			++iter;
		}
	}
	for (auto c : melted)
	{
		board[c.first][c.second] = INSIDE;
		CheckForEmpty(c.first, c.second);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int answer = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if(board[i][j])	cheese.push_back({ i, j });
		}

	CheckForEmpty(0, 0);

	while (!cheese.empty())
	{
		Melt();
		++answer;
	}
	cout << answer;
}