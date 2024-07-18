#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	priority_queue<int> q;
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		int a; cin >> a;
		q.push(a);
		sum += a;
	}
	q.pop(); q.pop();
	cout << sum / 5 << "\n" << q.top();

    return 0;
}