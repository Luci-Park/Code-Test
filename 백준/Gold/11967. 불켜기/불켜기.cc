#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;
using pii = pair<int, int>;

int N;

bool map[100][100] = { false, };
bool visited[100][100] = { false, };
vector<pii> lights[10000];

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

bool isValid(int y, int x) { return 0 <= y && y < N && 0 <= x && x < N; }
int lightIdx(int y, int x) { return y * N + x; }
pii lightIdx(int idx) { int y = idx / N, x = idx % N; return { y, x }; }

int answer()
{
	int a = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			a += map[i][j];
	return a;
}

int main()
{
	int m;
	cin >> N >> m;
	while (m--)
	{
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		lights[lightIdx(x - 1, y - 1)].push_back({ a - 1, b - 1});
	}
	set<pii> possible;
	queue<pii> q;
	q.push({ 0, 0 });
	map[0][0] = true;
	visited[0][0] = true;

	while (!q.empty())
	{
		while (!q.empty())
		{
			pii p = q.front(); q.pop();
			for (pii l : lights[lightIdx(p.first, p.second)])
				map[l.first][l.second] = true;

			for (int k = 0; k < 4; k++)
			{
				int ny = p.first + dy[k], nx = p.second + dx[k];
				if (!isValid(ny, nx)) continue;
				if (visited[ny][nx]) continue;
				if (!map[ny][nx]) { possible.insert({ ny, nx }); continue; }

				q.push({ ny, nx });
				visited[ny][nx] = true;
			}
		}
		for (auto iter = possible.begin(); iter != possible.end(); )
		{
			if (!map[iter->first][iter->second])
			{
				iter++;
			}
			else 
			{
				if (!visited[iter->first][iter->second])
				{
					q.push(*iter);
					visited[iter->first][iter->second] = true;
				}
				iter = possible.erase(iter);
			}			
		}
	}
	cout << answer();

	return 0;
}
