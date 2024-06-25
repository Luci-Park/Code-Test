#include <iostream>
#include <stack>
using namespace std;
int buildings[80000];
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> buildings[i];
	long answer = 0;
	stack<pair<int, int>> s;
	for (int i = n - 1; i >= 0; i--)
	{
		while (!s.empty() && s.top().first < buildings[i]) s.pop();
		if (s.empty())
			answer += n - i - 1;
		else
			answer += s.top().second - i - 1;

		s.push({ buildings[i], i });
	}
	cout << answer;
	return 0;
}