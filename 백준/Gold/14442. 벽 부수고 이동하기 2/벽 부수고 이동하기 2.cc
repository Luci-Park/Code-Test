#include <iostream>
#include <queue>

using namespace std;

struct pos
{
	int y, x, k;
public:
	pos(int y, int x, int k):y(y), x(x), k(k){}
};

int map[1000][1000];
int visited[1000][1000][10] = { 0 };
int N, M, K;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

bool isValid(int y, int x)
{
	return 0 <= y && y < N && 0 <= x && x < M;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int answer = -1;
	queue<pos> q;

	cin >> N >> M >> K;
	
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
			map[i][j] = str[j] - '0';
	}

	q.emplace(0, 0, 0);
	visited[0][0][0] = 1;
	
	while (!q.empty())
	{
		pos p = q.front(); q.pop();
		if (p.y == N - 1 && p.x == M - 1)
		{
			answer = visited[p.y][p.x][p.k];
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = p.y + dy[i], nx = p.x + dx[i], nk = p.k;
			if (!isValid(ny, nx)) continue;
			if (map[ny][nx])
			{
				if (nk >= K) continue;
				nk++;
			}
			if (visited[ny][nx][nk] > 0) continue;
			visited[ny][nx][nk] = visited[p.y][p.x][p.k] + 1;
			q.emplace(ny, nx, nk);
		}
	}
	cout << answer;

	return 0;
}