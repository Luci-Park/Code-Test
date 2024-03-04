#include <iostream>
using namespace std;
bool dp[2000][2000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int numbers[2000];
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> numbers[i];
	
	for (int i = 0; i < n; i++)
		dp[i][i] = true;

	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (i + 1 == j && numbers[i] == numbers[j])
				dp[i][j] = true;
			else if (dp[i + 1][j - 1] && numbers[i] == numbers[j])
				dp[i][j] = true;
		}
	}

	cin >> m;
	while (m--)
	{
		int s, e; cin >> s >> e;
		s--; e--;
		if (dp[s][e])
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}

	return 0;
}