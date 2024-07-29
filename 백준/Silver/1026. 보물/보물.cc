#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	priority_queue<int> A, B;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		A.push(a);
	}
	for (int i = 0; i < n; i++)
	{
		int b; cin >> b;
		B.push(-b);
	}
	long long s = 0;
	for (int i = 0; i < n; i++)
	{
		s += A.top() * -B.top();
		A.pop();
		B.pop();
	}
	cout << s;
	return 0;
}