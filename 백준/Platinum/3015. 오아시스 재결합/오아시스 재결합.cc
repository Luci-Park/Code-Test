#include <iostream>
#include <stack>
using namespace std;
int arr[500000];
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	long answer = 0;

	stack<pair<int,int>> s;
	for (int i = n - 1; i >= 0; i--)
	{
		int sameCount = 1;
		while (!s.empty() && s.top().first <= arr[i])
		{
			answer += s.top().second;
			if (s.top().first == arr[i]) sameCount += s.top().second;
			s.pop();
		}
		if (!s.empty()) answer += 1;
		s.push({ arr[i], sameCount });
	}

	cout << answer;

	return 0;
}