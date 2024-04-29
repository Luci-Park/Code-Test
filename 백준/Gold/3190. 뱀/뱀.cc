#include <iostream>
#include <queue>

using namespace std;
int board[100][100] = { 0, };
pair<unsigned int, char> turns[100];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, l; cin >> n >> k;
	deque<pair<int, int>> snake;
	snake.push_back({ 0, 0 });
	int dir = 0;

	while (k--)
	{
		int y, x; cin >> y >> x;
		board[y - 1][x - 1] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int x; char d; cin >> x >> d;
		turns[i] = { x, d };
	}
	int time = 1;
	int idx = 0;

	board[snake.front().first][snake.front().second] = 2;
	while(true)
	{
		//초 시작
		snake.push_front({ snake.front().first + dy[dir], snake.front().second + dx[dir] });
		
		auto head = snake.front();
		if (head.first < 0 || head.first >= n || head.second < 0 || head.second >= n) break;
		if (board[head.first][head.second] == 2) break;
		if (board[head.first][head.second] != 1) { auto tail = snake.back(); board[tail.first][tail.second] = 0; snake.pop_back(); }

		board[head.first][head.second] = 2;

		if (idx < l && turns[idx].first == time)
		{
			if (turns[idx].second == 'L') dir = (dir + 1) % 4;
			if (turns[idx].second == 'D') dir = (dir - 1 + 4) % 4;
			idx += 1;
		}
		time += 1;
	}

	cout << time;



	return 0;
}