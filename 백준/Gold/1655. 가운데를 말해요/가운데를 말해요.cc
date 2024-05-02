#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<int> minPQ;
	priority_queue<int, vector<int>, greater<int>> maxPQ;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num; cin >> num;
		if (minPQ.empty()) minPQ.push(num);
		else if(minPQ.size() == maxPQ.size())
		{
			if (num <= maxPQ.top()) minPQ.push(num);
			else
			{
				minPQ.push(maxPQ.top());
				maxPQ.pop();
				maxPQ.push(num);
			}
		}
		else
		{
			if (num >= minPQ.top())maxPQ.push(num);
			else
			{
				maxPQ.push(minPQ.top());
				minPQ.pop();
				minPQ.push(num);
			}
		}

		cout << minPQ.top() << "\n";
	}
	return 0;
}