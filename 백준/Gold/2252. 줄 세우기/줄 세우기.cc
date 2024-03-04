#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> adj;
vector<int> degreeCnt, answer;

void topsort()
{
	queue<int> q;
	for (int i = 1; i < adj.size(); i++)
	{
		if (degreeCnt[i] == 0)
			q.push(i);
	}
	for (int i = 1; i < adj.size(); i++)
	{
		if (q.empty()) return;
		int cur = q.front();
		answer.push_back(cur);
		q.pop();
		for (int j = 0; j < adj[cur].size(); j++)
		{
			int nxt = adj[cur][j];
			if (--degreeCnt[nxt] == 0)
				q.push(nxt);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	adj = vector<vector<int>>(n + 1);
	degreeCnt = vector<int>(n + 1, 0);
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		degreeCnt[b]++;
	}
	topsort();
	for (int i = 0; i < n; i++)
	{
		cout << answer[i] << " ";
	}

	return 0;
}