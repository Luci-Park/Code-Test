#include <iostream>
#include <numeric>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	int num = 1000000000;
	int dp[100][10] = { 0, };
	for (int i = 1; i < 10; i++)
		dp[0][i] = 1;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j - 1 >= 0)
			{
				dp[i][j - 1] = (dp[i][j - 1] + dp[i - 1][j]) % num;
			}
			if (j + 1 < 10)
			{
				dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j]) % num;
			}
		}
	}
	int count = 0;
	for (int i = 0; i < 10; i++)
		count = (count + dp[n - 1][i]) % num;
	cout << count;
	
	return 0;
}