#include <iostream>
#define INF 10000001
using namespace std;
int colors[1000][3];
int dp[1000][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> colors[i][j];
	}
	int ans = INF;
	for (int c = 0; c < 3; c++)
	{
		dp[0][c] = colors[0][c];
		int col1 = (c + 1) % 3;
		int col2 = (c + 2) % 3;
		dp[0][col1] = dp[0][col2] = INF;
		for (int i = 1; i < n; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + colors[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + colors[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + colors[i][2];
		}
		ans = min(ans, min(dp[n -1][col1], dp[n - 1][col2]));
	}
	cout << ans;
	return 0;
}