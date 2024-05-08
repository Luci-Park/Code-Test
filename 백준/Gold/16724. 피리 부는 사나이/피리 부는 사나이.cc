#include <iostream>
#include <stack>
using namespace std;

int dy[4]{ -1, 1, 0, 0 };
int dx[4]{ 0, 0, -1, 1 };
int board[1000][1000];
int visit[1000][1000];
int N, M;
stack<pair<int, int>> s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char c; cin >> c;
			if ('U' == c) board[i][j] = 0;
			if ('D' == c) board[i][j] = 1;
			if ('L' == c) board[i][j] = 2;
			if ('R' == c) board[i][j] = 3;
			visit[i][j] = 0;
		}
	}
	int section = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visit[i][j]) continue;
			int nsec = section;

			s.push({ i, j });
			visit[i][j] = nsec;
			while (true)
			{
				int r = s.top().first, c = s.top().second;
				int dir = board[r][c];
				int y = r + dy[dir], x = c + dx[dir];
				if (y < 0 || y >= N || x < 0 || x >= M) break;
				else if (visit[y][x]) { nsec = visit[y][x]; break; }
				s.push({ y, x });
				visit[y][x] = nsec;
			}
			while (!s.empty())
			{
				int r = s.top().first, c = s.top().second; s.pop();
				visit[r][c] = nsec;
			}
			if (nsec == section) section += 1;
		}
	}
	cout << section - 1;
	return 0;
}
