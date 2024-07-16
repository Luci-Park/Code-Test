#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
bool slates[5][4][5][5];
struct pos
{
	int z, y, x;
	pos(int z, int y, int x) :z(z), y(y), x(x) {}
	pos(const pos& other) :x(other.x), z(other.z), y(other.y) {}
	void operator+= (const pos& other) { z += other.z; y += other.y; x += other.x; }
	pos operator+ (const pos& other) { return pos(z + other.z, y + other.y, x + other.x); }
	bool operator==(const pos& other) { return other.z == z && other.y == y && other.x == x; }
};

pos d[] = { {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1} };
pos corners[] = { {0, 0, 0}, {0, 0, 4}, {0, 4, 0}, {0, 4, 4}, {4, 4, 4}, {4, 4, 0}, {4, 0, 4}, {4, 0, 0} };

bool map[5][5][5];
bool used[5] = { false };

int bfs(const pos& start, const pos& end)
{
	if (!map[start.z][start.y][start.x] || !map[end.z][end.y][end.x]) return -1;
	int visited[5][5][5];
	memset(visited, -1, sizeof(visited));

	queue<pos> q;
	visited[start.z][start.y][start.x] = 0;
	q.push(start);
	while (!q.empty())
	{
		pos p = q.front(); q.pop();
		if (p == end) break;
		int v = visited[p.z][p.y][p.x];
		for (int i = 0; i < 6; i++)
		{
			pos np = p + d[i];
			if (np.z < 0 || np.y < 0 || np.x < 0 || np.z >= 5 || np.y >= 5 || np.x >= 5) continue;
			if (visited[np.z][np.y][np.x] >= 0 || !map[np.z][np.y][np.x]) continue;
			visited[np.z][np.y][np.x] = v + 1;
			q.push(np);
		}
	}
	return visited[end.z][end.y][end.x];
}

int dfs(int depth)
{
	int answer = -1;
	if (depth == 5)
	{
		for (int i = 0; i < 4; i++)
		{
			int a = bfs(corners[i], corners[4 + i]);
			if (a >= 0 && (answer == -1 || a < answer)) answer = a;
		}
		return answer;
	}
	for (int i = 0; i < 5; i++)
	{
		if (used[i]) continue;
		used[i] = true;
		for (int j = 0; j < 4; j++)
		{
			for (int a = 0; a < 5; a++)
				for (int b = 0; b < 5; b++)
					map[depth][a][b] = slates[i][j][a][b];
			int a = dfs(depth + 1);
			if (a >= 0 && (answer == -1 || a < answer)) answer = a;
		}
		used[i] = false;
	}
	return answer;
}

void rotate(int slate, int idx)
{
	int arr[5][5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			slates[slate][idx + 1][i][j] = slates[slate][idx][5 - j - 1][i];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int k = 0; k < 5; k++)
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				cin >> slates[k][0][i][j];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 3; j++)
			rotate(i, j);

	cout << dfs(0);

	return 0;
}