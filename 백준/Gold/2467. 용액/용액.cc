#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	vector<long> amounts;
	pair<long, long> answer;
	cin >> n;
	while (n--)
	{
		long num;
		cin >> num;
		amounts.push_back(num);
	}
	int a = 0, b = amounts.size() - 1;
	long rslt = abs(amounts[a] + amounts[b]);
	answer.first = amounts[a];
	answer.second = amounts[b];
	while (a < b)
	{
		long num = amounts[a] + amounts[b];
		if (abs(num) < rslt)
		{
			rslt = abs(num);
			answer.first = amounts[a];
			answer.second = amounts[b];
		}
		if (num < 0)
			a++;
		else
			b--;
	}
	cout << answer.first << " " << answer.second;
	return 0;
}