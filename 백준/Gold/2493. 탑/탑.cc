#include <iostream>
#include <stack>
using namespace std;
stack<pair<int, int>> s;
int answers[500000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; 
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int height;
		cin >> height;
		while (!s.empty() && s.top().first < height) s.pop();
		if (s.empty()) answers[i] = 0;
		else answers[i] = s.top().second;
		s.push({ height, i + 1 });
	}

	for (int i = 0; i < n; i++)
		cout << answers[i] <<" ";

	return 0;
}