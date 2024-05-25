#include <iostream>
#include <queue>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int x; cin >> x;
	int sum = 64;
	priority_queue<int> sticks;
	sticks.push(-64);
	int count = 1;
	while (x != sum)
	{
		int smallstick = -sticks.top(); sticks.pop();
		int half = smallstick * 0.5f;
		if (sum - half < x)
		{
			sticks.push(-half);
			sticks.push(-half);
			count += 1;
		}
		else
		{
			sticks.push(-half);
			sum -= half;
		}
	}
	cout << count;

	return 0;
}