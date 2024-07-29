#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	priority_queue<int,vector<int>, greater<int>> pq;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		pq.push({a});
	}
	long long answer = 0;
	while (!pq.empty())
	{
		long long p = pq.top() * pq.size();
		answer = max(answer, p);
		pq.pop();
	}
	cout << answer;
	return 0;
}