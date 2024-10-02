#include <iostream>
#include <queue>

using namespace std;

struct pos
{
	int y, x, k;
};

int map[200][200];
int visited[200][200][31]{ 0 };
int W, H, K;

int dy[] = { 0, 1, 0, -1, -1, -1, -2, -2, 2, 2, 1, 1 };
int dx[] = { 1, 0, -1, 0, 2, -2, 1, -1, 1, -1, 2, -2 };

bool isValid(int y, int x)
{
	return !(y < 0 || y >= H || x < 0 || x >= W);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> K >> W >> H;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> map[i][j];

	queue<pos> q;
	visited[0][0][0] = 1;
	q.push({ 0, 0, 0 });
	int answer = -1;

	while (!q.empty())
	{
		pos f = q.front(); q.pop();
		if (f.y == H - 1 && f.x == W - 1)
		{
			answer = visited[f.y][f.x][f.k] - 1;
			break;
		}
		for (int i = 0; i < 12; i++)
		{
			if (i >= 4 && f.k >= K) break;
			int ny = f.y + dy[i], nx = f.x + dx[i], nk = f.k + ( i >= 4 ? 1 : 0);
			if (!isValid(ny, nx) || map[ny][nx]) continue;
			if (visited[ny][nx][nk]) continue;
			visited[ny][nx][nk] = visited[f.y][f.x][f.k] + 1;
			q.push({ ny, nx, nk });			
		}
	}
	cout << answer;

	return 0;
}