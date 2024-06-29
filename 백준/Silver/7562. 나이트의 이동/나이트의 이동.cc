#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int knight(int n, pair<int, int> start, pair<int,int> end)
{
	vector<vector<int>> visited(n, vector<int>(n, -1));
	queue<pair<int,int>> q;
	q.push(start);
	visited[start.first][start.second] = 0;

	while (!q.empty())
	{
		auto p = q.front(); q.pop();
		if (p == end) break;
		for (int i = 0; i < 8; i++)
		{
			int ny = p.first + dy[i], nx = p.second + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] >= 0) continue;
			visited[ny][nx] = visited[p.first][p.second] + 1;
			q.push({ ny, nx });
		}
	}
	return visited[end.first][end.second];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n; int sa, sb, ea, eb;
		cin >> n >> sa >> sb >> ea >> eb;
		cout << knight(n, { sa, sb }, { ea, eb }) << "\n";
	}

    return 0;
}