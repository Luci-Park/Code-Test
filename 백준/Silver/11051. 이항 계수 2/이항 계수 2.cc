#include <iostream>
using namespace std;
int dp[1001][1001];
int mod = 10007;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, K; cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
		}
	}
	cout << dp[N][K];

	return 0;
}