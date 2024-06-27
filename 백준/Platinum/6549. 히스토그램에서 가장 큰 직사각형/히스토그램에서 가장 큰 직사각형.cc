#include <iostream>
#include <stack>
using namespace std;
long long arr[100000];
int maxFor[100000];
int maxBack[100000];
int n;
long long histogram()
{
	stack<pair<int,int>> s;
	for (int i = n - 1; i >= 0; i--)
	{
		while (!s.empty() && s.top().first > arr[i])
		{
			maxBack[s.top().second] = i + 1;
			s.pop();
		}
		if (!s.empty() && s.top().first == arr[i])
		{
			maxFor[i] = maxFor[s.top().second];
			maxBack[i] = maxBack[s.top().second];
			maxFor[s.top().second] = -1;
			maxBack[s.top().second] = -1;
			s.top().second = i;
		}
		else
		{
			maxFor[i] = s.empty() ? n - 1 : s.top().second - 1;
			maxBack[i] = 0;
			s.push({ arr[i], i });
		}
	}
	long long answer = 0;
	for (int i = 0; i < n; i++)
	{
		if (maxFor[i] == -1) continue;
		long long size = arr[i] * (maxFor[i] - maxBack[i] + 1);
		answer = max(answer, size);
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	while (n > 0)
	{
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		long long answer = histogram();
		cout << answer << "\n";
		cin >> n;
	}

	return 0;
}