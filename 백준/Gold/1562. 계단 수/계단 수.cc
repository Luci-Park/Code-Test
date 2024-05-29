#include <iostream>
using namespace std;
int dp[100][10][1024] = { 0 };
int mod = 1000000000;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);	
	int n;
	cin >> n;
	for (int j = 1; j < 10; j++)
	{
		dp[0][j][1 << j] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 1024; k++)
			{
				if (j - 1 >= 0)
					dp[i][j - 1][k | 1 << (j - 1)] 
						= (dp[i][j - 1][k | 1 << (j - 1)] + dp[i - 1][j][k]) % mod;
				
				if (j + 1 < 10)
					dp[i][j + 1][k | 1 << (j + 1)]
						= (dp[i][j + 1][k | 1 << (j + 1)] + dp[i - 1][j][k]) % mod;
			}
		}
	}

	int sum = 0;
	for (int j = 0; j < 10; j++)
	{
		sum = (sum + dp[n - 1][j][1023]) % mod;
	}
	cout << sum;
	return 0;
}