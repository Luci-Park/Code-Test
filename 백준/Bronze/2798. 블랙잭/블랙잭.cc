#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	int cards[100];
	int answer = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> cards[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				int cardSum = cards[i] + cards[j] + cards[k];
				if (cardSum <= m && m - cardSum < m - answer)
				{
					answer = cardSum;
				}
			}
		}
	}
	cout << answer;

	return 0;
}