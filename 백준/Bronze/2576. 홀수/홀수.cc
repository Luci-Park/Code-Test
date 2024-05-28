#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);	
	int minOdd = 100;
	int sum = 0;
	for (int i = 0; i < 7; i++)
	{
		int n; cin >> n;
		if (!(n% 2)) continue;
		sum += n;
		if (n < minOdd) minOdd = n;
	}
	if (minOdd == 100) cout << -1;
	else cout << sum << "\n" << minOdd;

	return 0;
}