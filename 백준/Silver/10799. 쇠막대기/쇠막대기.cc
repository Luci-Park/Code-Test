#include <iostream>
#include <stack>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string str; cin >> str;
	long long count = 0;
	stack<char> s;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(') s.push(str[i]);
		else
		{
			s.pop();
			count += str[i - 1] == str[i] ? 1 : s.size();
		}
	}
	cout << count;
    return 0;
}