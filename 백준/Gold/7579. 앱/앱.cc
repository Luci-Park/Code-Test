#include <iostream>
#include <algorithm>
using namespace std;
#define MAXCOST 10000
long m;
long ms[101];
long cs[101];
long memoryCost[101][MAXCOST + 1] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> ms[i];
	for (int i = 1; i <= n; i++)
		cin >> cs[i];
	long answer = MAXCOST;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= MAXCOST; j++)
		{
			if (j - cs[i] < 0) memoryCost[i][j] = memoryCost[i - 1][j];
			else memoryCost[i][j] = max(memoryCost[i - 1][j], memoryCost[i - 1][j - cs[i]] + ms[i]);
			if (memoryCost[i][j] >= m && j < answer) answer = j;
		}
	}
	cout << answer;
	return 0;
}