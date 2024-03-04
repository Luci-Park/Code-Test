#include <iostream>
using namespace std;
int scores[100001] = { 0, };
int card[100001] = { 0, };
int cards[1000001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> card[i];
		cards[card[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = card[i] * 2; j <= 1000000; j += card[i])
		{
			if (cards[j])
			{
				scores[i]++;
				scores[cards[j]]--;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << scores[i] << " ";
	return 0;
}