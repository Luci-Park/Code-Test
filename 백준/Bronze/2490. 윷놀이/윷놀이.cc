#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		for (int j = 0; j < 4; j++)
		{
			int n; cin >> n;
			sum += n;
		}
		char ch = 'E';
		if (sum == 3)
			ch = 'A';
		if (sum == 2)
			ch = 'B';
		if (sum == 1)
			ch = 'C';
		if (sum == 0)
			ch = 'D';
		cout << ch << "\n";
	}
	return 0;
}