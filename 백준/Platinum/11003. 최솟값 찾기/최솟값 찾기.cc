#include <iostream>
#include <queue>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long l, n;
	priority_queue<pair<long, long>> minNum;
	cin >> n >> l;
	
	for (long i = 0; i < n; i++)
	{
		while (!minNum.empty() && minNum.top().second * -1 < i - l + 1)
			minNum.pop();

		long num; cin >> num;
		minNum.push({ -num, -i });
		
		cout << -minNum.top().first << " ";
	}


	return 0;
}