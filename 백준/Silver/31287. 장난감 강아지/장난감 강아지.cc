#include <iostream>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int dy[] = { -1, 1, 0, 0 };
	int dx[] = { 0, 0, -1, 1 };
	int n;
	long k;
	string s;
	cin >> n >> k >> s;
	long y = 0, x = 0;
	bool flag = false;
	if (k > n / 2) k = n / 2;
	for (int i = 0; i < n * k; i++)
	{
		int idx = 0;
		switch (s[i % n])
		{
		case 'U': idx = 0; break;
		case 'D': idx = 1; break;
		case 'L': idx = 2; break;
		case 'R': idx = 3; break;
		}
		y += dy[idx];
		x += dx[idx];
		if (y == 0 && x == 0) {
			flag = true; break;
		}
	}
	if (flag) cout << "YES";
	else cout << "NO";

	return 0;
}