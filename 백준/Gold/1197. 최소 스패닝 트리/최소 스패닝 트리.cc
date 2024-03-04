#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pir;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int v, e;
	cin >> v >> e;
	vector<vector<int>> adj[10000];
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	priority_queue<pir, vector<pir>, greater<pir>> pq;
	vector<bool> visited(v, false);
	int answer = 0;

	pq.push({ 0, 0 });
	while (!pq.empty())
	{
		auto p = pq.top(); pq.pop();
		int w = p.first;
		int u = p.second;
		if (visited[u]) continue;

		answer += w;
		visited[u] = true;

		for (auto verx : adj[u])
		{
			if (!visited[verx[0]])
				pq.push({ verx[1], verx[0] });
		}
	}
	cout << answer;
	return 0;
}