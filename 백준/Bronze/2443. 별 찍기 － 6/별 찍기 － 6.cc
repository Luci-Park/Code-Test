#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int T = 2 * n - 1;
	for (int i = n; i > 0; i--)
	{
		int t = 2 * i - 1;
		int space = (T - t) / 2;
		while (space--)
			cout << " ";
		while (t--)
			cout << "*";
		cout << "\n";
	}

	return 0;
}