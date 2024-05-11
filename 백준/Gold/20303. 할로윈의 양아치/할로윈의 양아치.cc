#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;

int candy[30000];
bool visited[30000] = { false, };
vector<list<int>> graph(30000);
vector<pair<int, int>> finalcandies;
int dp[30001][3001] = { 0, };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	finalcandies.reserve(n);
	for (int i = 0; i < n; i++)
		cin >> candy[i];
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < n; i++)
	{
		if (visited[i]) continue;
		visited[i] = true;
		stack<int> s;
		s.push(i);
		int candies = 0;
		int children = 0;
		while (!s.empty())
		{
			int child = s.top(); s.pop();
			candies += candy[child];
			children += 1;
			for (auto c : graph[child])
			{
				if (visited[c]) continue;
				visited[c] = true;
				s.push(c);
			}
		}
		finalcandies.push_back({ candies, children });
	}
	m = finalcandies.size();
	for (int i = 1; i <= m; i++)
	{
		int candies = finalcandies[i - 1].first;
		int children = finalcandies[i - 1].second;
		for (int j = 1; j < k; j++)
		{
			if (j - children < 0)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - children] + candies);
		}
	}
	cout << dp[m][k - 1];

	return 0;
}