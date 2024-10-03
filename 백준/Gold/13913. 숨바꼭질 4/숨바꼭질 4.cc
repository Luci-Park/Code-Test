#include <iostream>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;
int visited[100001] = { 0 };

void check(int x, int nx, queue<int>& q)
{
	if (nx < 0 || nx > 100000) return;
	if (visited[nx] != -1) return;
	visited[nx] = x;
	q.push(nx);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(visited, -1, sizeof(visited));
	int s, e;
	cin >> s >> e;

	queue<int> q({ s });
	visited[s] = s;

	while (!q.empty())
	{
		int x = q.front(); q.pop();
		if (x == e)
		{
			stack<int> st;
			while (visited[x] != x)
			{
				st.push(x);
				x = visited[x];
			}
			cout << st.size() << "\n";
			st.push(x);
			while (!st.empty())
			{
				cout << st.top() << " ";
				st.pop();
			}
			break;
		}
		check(x, x - 1, q);
		check(x, x + 1, q);
		check(x, x * 2, q);
	}

	return 0;
}