#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
const int MAX = numeric_limits<int>::max() / 3;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, s, e;
	cin >> n >> m;
	vector<pair<int, int>> cities(n + 1, {MAX, 0});
	vector<vector<pair<int, int>>> bus(n + 1);
	vector<int> path;

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		bus[a].push_back({ b, c });
	}
	cin >> s >> e;
	cities[s].first = 0;
	cities[s].second = s;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, s });
	while (!pq.empty())
	{
		int city = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (cost > cities[city].first) continue;
		if (city == e) break;
		for (int i = 0; i < bus[city].size(); i++)
		{
			auto edge = bus[city][i];
			if (cities[edge.first].first > cities[city].first + edge.second)
			{
				cities[edge.first].first = cities[city].first + edge.second;
				cities[edge.first].second = city;
				pq.push({ -cities[edge.first].first, edge.first });
			}
		}
	}
	int city = e;
	while (city != s)
	{
		path.push_back(city);
		city = cities[city].second;
	}
	path.push_back(s);
	cout << cities[e].first << "\n" << path.size() << "\n";
	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i] << " ";

	return 0;
}