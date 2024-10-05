#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int y = 0, m = 0;

	for (int i = 0; i < n; i++)
	{
		int time; cin >> time;
		y += (time + 30)/30 * 10;
		m += (time + 60)/60 * 15;
	}

	if (y < m)
		cout << "Y " << y;
	else if (y == m)
		cout << "Y M " << y;
	else
		cout << "M " << m;

	return 0;
}