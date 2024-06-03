#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
deque<int> dq;
int n, m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		dq.push_back(i);
	
	int count = 0;
	while (m--)
	{
		int target; cin >> target;
		auto iter = find(dq.begin(), dq.end(), target);
		if (iter - dq.begin() < dq.end() - iter)
		{
			count += iter - dq.begin();
			while (dq.front() != target) { dq.push_back(dq.front()); dq.pop_front(); }
			dq.pop_front();
		}
		else
		{
			count += dq.end() - iter;
			while (dq.back() != target) { dq.push_front(dq.back()); dq.pop_back(); }
			dq.pop_back();
		}
	}
	cout << count;
	
	return 0;
}