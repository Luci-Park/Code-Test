#include <iostream>
#include <queue>
using namespace std;

int N, M, K;
bool map[1000][1000];
bool visited[1000][1000][11] = { false };
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

struct pos
{
	int y, x, k, t;
	pos(int y, int x, int k, int t) :y(y), x(x), k(k), t(t) {}
};
bool IsDay(int time) { return time % 2; }
bool IsValid(int y, int x) { return 0 <= y && y < N && 0 <= x && x < M; }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int answer = -1;

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		string str; cin >> str;
		for (int j = 0; j < M; j++)
			map[i][j] = str[j] - '0';
	}

	visited[0][0][K] = 1;
	queue<pos> q;
	q.emplace( 0, 0, K, 1 );
	
	while (!q.empty())
	{
		pos p = q.front(); q.pop();
		//cout << p.y << " " << p.x << " " << p.k << " " << visited[p.y][p.x][p.k] << "\n";
		if (p.y + 1 == N && p.x + 1 == M) { answer = p.t; break; }
		bool nightSelfAdded = false;
		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + p.y, nx = dx[i] + p.x;
			if (!IsValid(ny, nx)) continue;
			if (!map[ny][nx])
			{
				if (visited[ny][nx][p.k]) continue;
				visited[ny][nx][p.k] = true;
				q.emplace(ny, nx, p.k, p.t + 1);
			}
			else
			{
				if (p.k == 0) continue;
				int k = p.k - 1;
				if (visited[ny][nx][k]) continue;
				if (IsDay(p.t))
				{
					if (visited[ny][nx][k]) continue;
					visited[ny][nx][k] = true;
					q.emplace(ny, nx, k, p.t + 1);
				}
				else
				{
					if (visited[ny][nx][k]) continue;
					if (nightSelfAdded) continue;
					nightSelfAdded = true;
					q.emplace(p.y, p.x, p.k, p.t + 1);
				}
			}
		}
	}
	cout << answer;
	return 0;
}