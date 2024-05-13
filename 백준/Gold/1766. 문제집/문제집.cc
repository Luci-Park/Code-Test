#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;
int n = 0;
list<int> graph[32000];
int indegree[32000] = { 0, };
bool visited[32000] = { false, };
priority_queue<int> temp;
queue<int> answer;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin >> n >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		indegree[b - 1]++;
	}
	for (int i = 0; i < n; i++)
	{
		if (indegree[i]) continue;
		temp.push(-i);
		visited[i] = true;
	}
	while (!temp.empty())
	{
		int idx = -temp.top(); temp.pop();
		answer.push(idx + 1);
		for (int num : graph[idx])
		{
			if (visited[num]) continue;
			indegree[num] -= 1;
			if (indegree[num]) continue;
			temp.push(-num);
			visited[num] = true;
		}
	}
	while (!answer.empty())
	{
		cout << answer.front() << " ";
		answer.pop();
	}
	return 0;
}