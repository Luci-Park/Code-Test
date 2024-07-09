#include <iostream>
#include <queue>
using namespace std;
enum status { green, red, flower, empty };
struct target
{
	int y, x;
	status c;
	target() {}
	target(int y, int x, status c) : y(y), x(x), c(c) {}
};
struct color
{
	status c;
	int t;
	color() :t(0), c(status::empty) {}
	color(status c, int t) :c(c), t(t) {}
};

int N, M, G, R, T = 0;
int map[50][50];
target ts[10];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int maxNum = 0;
bool isOther(status a, status b) { return ((a == status::red && b == status::green) || (a == status::green && b == status::red)); }

void check()
{
	color arr[50][50];
	queue<target> q;
	for (int i = 0; i < T; i++)
	{
		if (ts[i].c == status::empty) continue;
		q.push(ts[i]);
		arr[ts[i].y][ts[i].x] = color(ts[i].c, 0);
	}
	int count = 0;
	while (!q.empty())
	{
		target t = q.front(); q.pop();
		if (arr[t.y][t.x].c == status::flower) continue;
		int time = arr[t.y][t.x].t;
		for (int i = 0; i < 4; i++)
		{
			int ny = t.y + dy[i], nx = t.x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (map[ny][nx] == 0) continue;
			if (isOther(arr[ny][nx].c, t.c) && arr[ny][nx].t == time + 1)
			{
				arr[ny][nx].c = status::flower;
				count += 1;
				continue;
			}
			if (arr[ny][nx].c == status::empty)
			{
				arr[ny][nx].c = t.c;
				arr[ny][nx].t = time + 1;
				q.emplace(ny, nx, t.c);
			}
		}
	}
	maxNum = max(count, maxNum);
}

void choose(int depth, int g, int r)
{
	if (g == 0 && r == 0) 
	{ 
		check(); 
		return; 
	}
	if (g)
	{
		ts[depth].c = status::green;
		choose(depth + 1, g - 1, r);
		ts[depth].c = status::empty;
	}
	if (r)
	{
		ts[depth].c = status::red;
		choose(depth + 1, g, r - 1);
		ts[depth].c = status::empty;
	}
	if (T - depth - 1 >= g + r)
	{
		ts[depth].c = status::empty;
		choose(depth + 1, g, r);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> R >> G;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2) ts[T++] = target(i, j, status::empty);
		}
	choose(0, R, G);
	cout << maxNum;
	return 0;
}