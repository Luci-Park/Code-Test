#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int board[20][20] = { 0, };
	int dice[6] = { 0, };
	int dx[5] = { 0, 1, -1, 0, 0 };
	int dy[5] = { 0, 0, 0, -1, 1 };
	int commands[1000];

	int n, m, x, y, k;
	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	for (int i = 0; i < k; i++)
		cin >> commands[i];
	for (int i = 0; i < k; i++)
	{
		int command = commands[i];
		int ny = y + dy[command], nx = x + dx[command];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		y = ny; x = nx;
		int temp;
		switch (command)
		{
		case 1:
			temp = dice[2];
			dice[2] = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[0];
			dice[0] = temp;
			break;
		case 2:
			temp = dice[2];
			dice[2] = dice[0];
			dice[0] = dice[3];
			dice[3] = dice[1];
			dice[1] = temp;
			break;
		case 3:
			temp = dice[4];
			dice[4] = dice[0];
			dice[0] = dice[5];
			dice[5] = dice[1];
			dice[1] = temp;
			break;
		case 4:
			temp = dice[4];
			dice[4] = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[0];
			dice[0] = temp;
			break;
		}

		if (!board[y][x])
			board[y][x] = dice[1];
		else
		{
			dice[1] = board[y][x];
			board[y][x] = 0;
		}
		cout << dice[0] <<"\n";
	}
	return 0;
}