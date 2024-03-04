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
	int n, m;
	cin >> n >> m;
	vector<vector<pir>> town(n);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		town[a].push_back({ b, c });
		town[b].push_back({ a, c });
	}

	priority_queue < pir, vector<pir>, greater<pir>>pq;
	vector<bool>visited(n);
	pq.push({ 0, 0 });
	int answer = 0;
	int largest = 0;

	while (!pq.empty())
	{
		auto p = pq.top(); pq.pop();
		int u = p.second;
		int price = p.first;
		if (visited[u])
			continue;
		visited[u] = true;
		answer += price;
		if (price > largest)
			largest = price;
		for (auto v : town[u])
		{
			if (visited[v.first])
				continue;
			pq.push({ v.second, v.first });
		}
	}
	answer -= largest;
	cout << answer;
	return 0;
}