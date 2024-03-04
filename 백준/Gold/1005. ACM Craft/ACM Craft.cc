#include <iostream>
#include <vector>

using namespace std;
int Cost[1000];
vector<int> visited;
vector<vector<int>> connection;

int CalCost(int w)
{
	int cost = Cost[w];
	int maxChildCost = 0;
	for (auto u : connection[w])
	{
		int c = visited[u];
		if (c < 0)
			c = CalCost(u);
		if (c > maxChildCost)
			maxChildCost = c;
	}
	visited[w] = cost + maxChildCost;
	return cost + maxChildCost;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	int answ[5];
	while (t--)
	{
		int n, k, w;
		cin >> n >> k;
		connection = vector<vector<int>>(n);
		visited = vector<int>(n, -1);
		for (int i = 0; i < n; i++)
			cin >> Cost[i];
		while (k--)
		{
			int x, y;
			cin >> x >> y;
			x--; y--;
			connection[y].push_back(x);
		}
		cin >> w;
		cout << CalCost(--w) <<"\n";
	}
	return 0;
}