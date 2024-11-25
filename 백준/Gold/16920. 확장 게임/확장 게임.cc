#include <iostream>
#include <queue>

using namespace std;
struct pos
{
	int y, x, c;
	pos(int y, int x, int c):y(y), x(x), c(c){}
};

int N, M, P;
int s[9];
char map[1000][1000];
queue<pos> nq[9];
int answer[9] = { 0, };
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

bool isValid(int y, int x) { return 0 <= y && y < N && 0 <= x && x < M; }
void printMap()
{
	cout << "\n";
	for (int i = 0; i < N; i++)
		cout << map[i] << "\n";
	cout << "\n";
}

bool bfs(int idx)
{

}

int main()
{
	cin >> N >> M >> P;
	for (int i = 0; i < P; i++) cin >> s[i];
	for (int i = 0; i < N; i++)
	{
		string str; cin >> str;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = str[j];
			if (isdigit(str[j]))
			{
				nq[str[j] - '0' - 1].emplace(i, j, 0);
				answer[str[j] - '0' - 1] += 1;
			}
		}
	}
	bool possible = true;
	while (possible)
	{
		possible = false;
		for (int i = 0; i < P; i++)
		{
			queue<pos> q(nq[i]);
			nq[i] = queue<pos>();
			while (!q.empty())
			{
				pos p = q.front(); q.pop();
				for (int j = 0; j < 4; j++)
				{
					int ny = p.y + dy[j], nx = p.x + dx[j];
					if (!isValid(ny, nx)) continue;
					if (map[ny][nx] != '.') continue;
					if (p.c == s[i])
					{
						nq[i].emplace(p.y, p.x, 0);
						possible = true;
						break;
					}
					else
					{
						q.emplace(ny, nx, p.c + 1);
						map[ny][nx] = i + 1 + '0';
						answer[i] += 1;
					}
				}
			}
		}
	}
	for (int i = 0; i < P; i++)
		cout << answer[i] << " ";

	return 0;
}
