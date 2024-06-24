#include <iostream>
#include <deque>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long l, n;
	deque<pair<long, long>> minNum;
	cin >> n >> l;
	
	for (long i = 0; i < n; i++)
	{
		while (!minNum.empty() && (minNum.front().first < i - l + 1)) minNum.pop_front();
		long num; cin >> num;
		while (!minNum.empty() && minNum.back().second > num) minNum.pop_back();
		minNum.push_back({i, num});


		cout << minNum.front().second << " ";
	}

	return 0;
}