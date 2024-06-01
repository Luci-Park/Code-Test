#include <iostream>
#include <numeric>
using namespace std;

int p[2500][2500] = {};
int dp[2500] = {};
string str;
bool IsPelindrome(int a, int b)
{
	if (a >= b) return true;
	if (p[a][b])
	{
		return p[a][b] == 2;
	}
	if (str[a] == str[b])
	{
		if (IsPelindrome(a + 1, b - 1)) p[a][b] = 2;
		else p[a][b] = 1;
	}
	else
	{
		p[a][b] = 1;
	}
	return p[a][b] == 2;
}

int dfs(int depth, int si)
{
	if (si >= str.size()) return 0;
	if (dp[si]) return dp[si];
	dp[si] = 2500;
	for (int i = str.size() - 1; i >= si; i--)
	{
		if (!IsPelindrome(si, i)) continue;
		int rslt = dfs(depth + 1, i + 1);
		dp[si] = min(rslt + 1, dp[si]);
	}
	return dp[si];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> str;
	cout << dfs(0, 0);
	
	
	return 0;
}