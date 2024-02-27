#include <iostream>
using namespace std;

const long long MOD = 1000000007;
long long inv(long long b)
{
	long long rslt = 1;
	long long exp = MOD - 2;
	while (exp)
	{
		if (exp & 1)
			rslt = rslt * b % MOD;
		b = b * b % MOD;
		exp >>= 1;
	}

	return rslt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m;
	long long answer = 0;
	cin >> m;
	while (m--)
	{
		long n, s;
		cin >> n >> s;
		answer = (answer + (s * inv(n)) % MOD);
	}
	cout << answer % MOD;
}