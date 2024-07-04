#include <iostream>
#include <queue>
using namespace std;
char map[30][30][30];
int visited[30][30][30];
int l, r, c;
int dz[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dx[] = { 0, 0, 0, 0, 1, -1 };
struct pos
{
	int z, y, x;
	pos() {};
	pos(int z, int y, int x):z(z),y(y),x(x){}
	pos(const pos& other) : z(other.z), y(other.y), x(other.x) {}
	bool operator==(const pos& other) { return z == other.z && y == other.y && x == other.x; }
	pos operator+(const pos& other) { return pos(z + other.z, y + other.y, x + other.x); }
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (true)
	{
		cin >> l >> r >> c;
		if (l == 0) break;
		pos e;
		queue<pos> q;
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < r; j++)
			{
				string str; cin >> str;
				for (int k = 0; k < c; k++)
				{
					map[i][j][k] = str[k];
					visited[i][j][k] = -1;
					if (map[i][j][k] == 'S')
					{
						q.emplace(i, j, k);
						visited[i][j][k] = 0;
					}
					else if (map[i][j][k] == 'E') e = pos(i, j, k);
				}
			}
		}
		while (!q.empty())
		{
			pos p = q.front(); q.pop();
			if (p == e) break;
			int v = visited[p.z][p.y][p.x];
			for (int i = 0; i < 6; i++)
			{
				pos np = p + pos(dz[i], dy[i], dx[i]);
				if (np.z < 0 || np.z >= l || np.y < 0 || np.y >= r || np.x < 0 || np.x >= c 
					|| visited[np.z][np.y][np.x] != -1 || map[np.z][np.y][np.x] == '#') continue;
				q.push(np);
				visited[np.z][np.y][np.x] = v + 1;
			}
		}
		if (visited[e.z][e.y][e.x] >= 0) cout << "Escaped in " << visited[e.z][e.y][e.x] <<" minute(s).\n";
		else cout << "Trapped!\n";
	}


    return 0;
}