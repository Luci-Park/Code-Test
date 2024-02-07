#include <iostream>
using namespace std;

int main()
{
	int T;
	int apart[15][15];
	cin >> T;
	for (int i = 0; i < 15; i++)
	{
		apart[i][1] = 1;
		apart[0][i] = i;
	}
	
	for (int i = 1; i < 15; i++)
	{
		for (int j = 2; j < 15; j++)
		{
			apart[i][j] = apart[i][j - 1] + apart[i - 1][j];
		}
	}

	while (T--)
	{
		int k, n;
		cin >> k >> n;
		cout << apart[k][n]<<"\n";
	}
	return 0;
}
