#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int cards[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int card; cin >> card;
		cards[card] = i;
	}
	
	int count = 0;
	
	for (int i = 2; i <= n; i++)
	{
		if (cards[i] < cards[i - 1]) count += 1;
	}
	
	cout << count;
	return 0;
}