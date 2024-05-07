#include <iostream>
#include <queue>
#define ICE 0
#define WATER 1
using namespace std;

int R, C;
bool board[1500][1500];
bool visit[1500][1500];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
queue<pair<int, int>> swanQ, swanB, waterQ, waterB;
pair<int, int> swan;
bool isValid(int y, int x)
{
	return (0 <= y && y < R && 0 <= x && x < C);
}

bool swan_check()
{
	while (!swanQ.empty())
	{
		auto p = swanQ.front(); swanQ.pop();
		if (p == swan) return true;

		for (int i = 0; i < 4; i++)
		{
			int y = p.first + dy[i], x = p.second + dx[i];
			if (!isValid(y, x) || visit[y][x]) continue;
			if (board[y][x] == WATER) swanQ.push({ y, x });
			else if (board[y][x] == ICE)swanB.push({ y, x });
			visit[y][x] = true;
		}
	}

	while (!swanB.empty()) { swanQ.push(swanB.front()); swanB.pop(); }

	return false;
}

void water_check()
{
	while (!waterQ.empty())
	{
		auto p = waterQ.front(); waterQ.pop();
		for (int i = 0; i < 4; i++)
		{
			int y = p.first + dy[i], x = p.second + dx[i];
			if (!isValid(y, x) || board[y][x] != ICE)  continue;
			board[y][x] = WATER;
			waterB.push({ y, x });
		}
	}

	while (!waterB.empty()) { waterQ.push(waterB.front()); waterB.pop(); }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C;
	int day = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			char c; cin >> c;
			if (c == 'X') board[i][j] = ICE;
			else
			{
				board[i][j] = WATER;
				waterQ.push({ i, j });
				if (c == 'L')
				{
					if (swanQ.empty()) { swanQ.push({ i, j }); visit[i][j] = true; }
					else swan = { i, j };
				}
			}
		}
	}
	while (!swan_check())
	{
		day += 1;
		water_check();
	}
	cout << day;
	return 0;
}
