#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, a, count = 0;
	cin >> n;
	while(n--)
	{
		cin >> a;
		bool flag = true;
		if (a == 1)
			flag = false;
		for (size_t i = 2; i * i <= a; i++)
		{
			if (a % i == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag) 
			count += 1;
	}
	cout << count;
	return 0;
}