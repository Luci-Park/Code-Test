#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	int nums[1000];

	int dp[1000];
	cin >> n;
	int mxN = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
		int mN = 0;
		for (int j = 0; j < i; j++)
		{
			if (nums[j] < nums[i] && dp[j] > mN) 
				mN = dp[j];
		}
		dp[i] = mN + nums[i];
		if (dp[i] > mxN) mxN = dp[i];
	}
	cout << mxN;
	return 0;
}