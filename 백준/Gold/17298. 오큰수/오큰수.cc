#include <iostream>
#include <stack>
using namespace std;
int arr[1000000];
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	stack<int> calc;
	stack<int> answer;

	for (int i = n - 1; i >= 0; i--)
	{
		while (!calc.empty() && calc.top() <= arr[i]) calc.pop();
		answer.push(calc.empty() ? -1 : calc.top());
		calc.push(arr[i]);
	}

	while (!answer.empty())
	{
		cout << answer.top() << " ";
		answer.pop();
	}
	

	return 0;
}