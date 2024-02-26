#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int items[101];
	vector<vector<int>> connectivity(101, vector<int>(101, INT_MAX * 0.3));
	int n, m, r;

	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
		cin >> items[i];

	for (int i = 0; i < r; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;
		connectivity[a][b] = l;
		connectivity[b][a] = l;
	}

	int itemCnt = 0;
	for(int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j)
					connectivity[i][j] = 0;
				else if (connectivity[i][j] >
					connectivity[i][k] + connectivity[k][j])
					connectivity[i][j] = connectivity[i][k] + connectivity[k][j];
			}
		}
	}

		for (int i = 1; i <= n; i++)
	{
		int item = 0;
		for (int j = 1; j <= n; j++)
		{
			if (connectivity[i][j] <= m)
				item += items[j];
		}
		if (item > itemCnt)
			itemCnt = item;
	}
	cout << itemCnt;
	return 0;
}