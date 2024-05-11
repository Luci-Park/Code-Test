#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

unsigned int n, k;
pair<unsigned int, unsigned int> jewels[300000];
unsigned int bags[300000];
priority_queue<unsigned int> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> jewels[i].first >> jewels[i].second;
	for (int i = 0; i < k; i++)
		cin >> bags[i];
	
	sort(jewels, jewels + n);
	sort(bags, bags + k);
	unsigned long sum = 0;
	for (int i = 0, j = 0; i < k; i++)
	{
		while (j < n && jewels[j].first <= bags[i])
			pq.push(jewels[j++].second);

		if (!pq.empty())
		{
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum;

	return 0;
}