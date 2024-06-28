#include <iostream>
#include <stack>
using namespace std;
bool isgood(string str)
{
	stack<char> s;
	for (int i = 0; i < str.size(); i++)
	{
		if (s.empty() || s.top() != str[i]) s.push(str[i]);
		else s.pop();
	}
	return s.empty();
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int answer = 0;
	while (n--)
	{
		string str;
		cin >> str;
		answer += isgood(str);
	}
	cout << answer;
	return 0;
}