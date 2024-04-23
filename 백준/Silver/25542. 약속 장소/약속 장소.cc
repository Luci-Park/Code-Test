#include <iostream>
#include <string>

using namespace std;
bool valid(string a, string b, int l)
{
	int count = 0;
	for (int i = 0; i < l; i++)
		if (a[i] != b[i]) count += 1;
	return count <= 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string stores[20];
	int n, l;
	cin >> n >> l;

	for (int i = 0; i < n; i++)
		cin >> stores[i];

	for (int i = 0; i < n; i++)
	{
		string placeholder = stores[i];
		for (int j = 0; j < l; j++)
		{
			char c = placeholder[j];
			for (char k = 'A'; k <= 'Z'; k++)
			{
				bool flag = true;
				placeholder[j] = k;
				for (int m = 0; m < n; m++)
				{
					if (!valid(placeholder, stores[m], l))
					{
						flag = false;
						break;
					}
				}
				if (flag)
				{
					cout << placeholder;
					return 0;
				}
			}
			placeholder[j] = c;
		}
	}
	cout << "CALL FRIEND";

	return 0;
}