#include <iostream>
#include <queue>

using namespace std;

int N;
int board[20][20];
int checkBoard()
{
	int M = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (board[i][j] > M)
				M = board[i][j];
	return M;
}

void copyBoard(int a[20][20], int b[20][20])
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			b[i][j] = a[i][j];
}
void up()
{
	for (int j = 0; j < N; j++)
	{
		queue<int> q;
		for (int i = 0; i < N; i++)
		{
			if (!board[i][j]) continue;
			if (q.empty() || q.back() != board[i][j]) q.push(board[i][j]);
			else q.back() *= -2;
			board[i][j] = 0;
		}
		int y = 0;
		while (!q.empty())
		{
			board[y++][j] = abs(q.front());
			q.pop();
		}
	}
}

void down()
{
	for (int j = 0; j < N; j++)
	{
		queue<int> q;
		for (int i = N - 1; i >= 0; i--)
		{
			if (!board[i][j]) continue;
			if (q.empty() || q.back() != board[i][j]) q.push(board[i][j]);
			else q.back() *= -2;
			board[i][j] = 0;
		}
		int y = N - 1;
		while (!q.empty())
		{
			board[y--][j] = abs(q.front());
			q.pop();
		}
	}
}
void left()
{
	for (int i = 0; i < N; i++)
	{
		queue<int> q;
		for (int j = 0; j < N; j++)
		{
			if (!board[i][j]) continue;
			if (q.empty() || q.back() != board[i][j]) q.push(board[i][j]);
			else q.back() *= -2;
			board[i][j] = 0;
		}
		int x = 0;
		while (!q.empty())
		{
			board[i][x++] = abs(q.front());
			q.pop();
		}
	}
}

void right()
{
	for (int i = 0; i < N; i++)
	{
		queue<int> q;
		for (int j = N - 1; j >= 0; j--)
		{
			if (!board[i][j]) continue;
			if (q.empty() || q.back() != board[i][j]) q.push(board[i][j]);
			else q.back() *= -2;
			board[i][j] = 0;
		}
		int x = N - 1;
		while (!q.empty())
		{
			board[i][x--] = abs(q.front());
			q.pop();
		}
	}
}

int dfs(int depth)
{
	if (depth > 5)
		return checkBoard();

	int boardSave[20][20];
	int max = 0;
	copyBoard(board, boardSave);

	for (int i = 0; i < 4; i++)
	{
		if (i == 0) up();
		if (i == 1) down();
		if (i == 2) left();
		if (i == 3) right();
		int rslt = dfs(depth + 1);
		if (rslt > max) max = rslt;
		copyBoard(boardSave, board);
	}
	return max;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	cout << dfs(1);
	return 0;
}