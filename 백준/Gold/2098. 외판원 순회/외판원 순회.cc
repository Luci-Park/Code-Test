#include <iostream>
#include <climits>
#define INF 1E8
using namespace std;

int dp[16][1<<16] = { 0 };
int w[16][16];
int n;

int tsp(int here, int visited)
{
	if (visited == (1 << n) - 1)
		return w[here][0] ? w[here][0] : INF;
	if (dp[here][visited] != -1) return dp[here][visited];
	int answer = INF;
	for (int i = 0; i < n; i++)
	{
		if (visited & (1 << i) || !w[here][i])continue;
		int cost = w[here][i] + tsp(i, visited | (1 << i));
		answer = min(answer, cost);
	}
	dp[here][visited] = answer;
	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> w[i][j];

	for (int i = 0; i < n; i++)
		fill_n(dp[i], size(dp[i]), -1);

	cout << tsp(0, 1);
	return 0;
}