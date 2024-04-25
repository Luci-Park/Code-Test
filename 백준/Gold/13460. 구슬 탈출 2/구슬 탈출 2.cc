#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;
char board[10][10];
int N, M;

pair<int, int> R;
pair<int, int> B;
pair<int, int> dir[4]{ {0,1}, {0, -1}, {-1, 0}, {1, 0} };
pair<int, int>operator+(const pair<int, int>& a, const pair<int, int>& b) { return { a.first + b.first, a.second + b.second }; }

int dfs(int depth)
{
	if (depth > 10) return -1;
	pair<int, int> r = R;
	pair<int, int> b = B;
	int minDepth = 11;
	for (int i = 0; i < 4; i++)
	{
		bool rFix = false, bFix = false;
		bool rFlag = false, bFlag = false;
		while (!rFix || !bFix)
		{
			if (!bFix)
			{
				pair<int, int>target = B + dir[i];
				switch (board[target.first][target.second])
				{
				case '.':
					board[B.first][B.second] = '.';
					B = target;
					board[B.first][B.second] = 'B';
					break;
				case 'R':
					if (rFix) bFix = true;
					break;
				case '#':
					bFix = true;
					break;
				case 'O':
					bFlag = true;
					bFix = true;
					board[B.first][B.second] = '.';
					break;
				}
			}
			if (!rFix)
			{
				pair<int, int>target = R + dir[i];
				switch (board[target.first][target.second])
				{
				case '.':
					board[R.first][R.second] = '.';
					R = target;
					board[R.first][R.second] = 'R';
					break;
				case 'B':
					if (bFix) rFix = true;
					break;
				case '#':
					rFix = true;
					break;
				case 'O':
					rFlag = true;
					rFix = true;
					board[R.first][R.second] = '.';
					break;
				}
			}
		}
		if (rFlag && !bFlag) 
			return depth;

		if (!rFlag && !bFlag)
		{
			int rslt = dfs(depth + 1);
			if (rslt != -1 && rslt < minDepth) minDepth = rslt;
		}
		board[B.first][B.second] = '.';
		board[R.first][R.second] = '.';
		R = r;
		B = b;
		board[B.first][B.second] = 'B';
		board[R.first][R.second] = 'R';
	}
	if (minDepth == 11) minDepth = -1;
	return minDepth;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'R') R = { i, j };
			if (board[i][j] == 'B') B = { i, j };
		}
	}

	cout << dfs(1);

	return 0;
}