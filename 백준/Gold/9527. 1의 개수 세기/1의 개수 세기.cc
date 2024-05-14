#include <iostream>
using namespace std;

long long dp[55];

long long numOf1(long long x)
{
	long long count = x & 1;
	for (int i = 54; i > 0; i--)
	{
		long long num = (long long)1 << i;
		if (x & num)
		{
			count += dp[i - 1] + (x - num + 1);
			x -= num;
		}
	}
	return count;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long a, b;
	cin >> a >> b;
	dp[0] = 1;
	for (int i = 1; i < 55; i++)
		dp[i] = dp[i - 1] * 2 + ((long long)1 << i);
	cout << numOf1(b) - numOf1(a - 1);
	
	return 0;
}