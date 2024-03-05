#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
float dist(pair<float, float> a, pair<float, float> b)
{
	float y = abs(a.first - b.first);
	float x = abs(a.second - b.second);
	y *= y;
	x *= x;
	return sqrt(y + x);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	pair<float,float> stars[100];
	bool visited[100]{ 0 };
	priority_queue<pair<float, int>> pq;

	for (int i = 0; i < n; i++)
		cin >> stars[i].second >> stars[i].first;
	
	for (int i = 1; i < n; i++)
		pq.push(make_pair(-dist(stars[0], stars[i]), i));
	
	visited[0] = true;
	float answer = 0;
	int count = 1;
	while (!pq.empty() && count < n)
	{
		pair<float, int> next = pq.top(); pq.pop();
		if (visited[next.second]) continue;
		visited[next.second] = true;
		answer -= next.first;
		count += 1;
		for (int i = 0; i < n; i++)
		{
			if (visited[i]) continue;
			if (i == next.second) continue;
			pq.push(make_pair(-dist(stars[next.second], stars[i]), i));
		}
	}
	cout << answer;

	return 0;
}