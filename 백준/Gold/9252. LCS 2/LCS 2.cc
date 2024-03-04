#include <iostream>
using namespace std;
int lcs[1001][1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str1, str2;
	cin >> str1 >> str2;
	for (int i = 0; i <= str1.size(); i++)
	{
		for (int j = 0; j <= str2.size(); j++)
		{
			if (i == 0 || j == 0)
				lcs[i][j] = 0;
			else if (str1[i - 1] == str2[j - 1])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}
	int y = str1.size();
	int x = str2.size();
	string rslt = "";
	while (lcs[y][x] != 0)
	{
		if (lcs[y - 1][x] == lcs[y][x])
			y--;
		else if (lcs[y][x - 1] == lcs[y][x])
			x--;
		else
		{
			rslt = str1[y - 1] + rslt;
			y--;
			x--;
		}
	}
	cout << lcs[str1.size()][str2.size()] << "\n" << rslt;

	return 0;
}