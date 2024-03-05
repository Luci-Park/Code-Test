#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

bool topologySort(vector<unordered_set<int>>& graph, vector<int>& indegree, stack<int>& rslt, int n)
{
	vector<bool> visited(n + 1, false);
	queue<int> temp;
	for (size_t i = 1; i <= n; i++)
	{
		if (indegree[i]) continue;
		temp.push(i);
		visited[i] = true;
	}
	if (temp.empty()) return false;
	while (!temp.empty())
	{
		int idx = temp.front(); temp.pop();
		rslt.push(idx);
		for (int i : graph[idx])
		{
			if (visited[i]) continue;
			indegree[i] -= 1;
			if (indegree[i])continue;
			temp.push(i);
			visited[i] = true;
		}
	}
	if (rslt.size() < n) return false;

	return true;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<unordered_set<int>> singers(n + 1);
	vector<int> indegree(n + 1, 0);
	while (m--)
	{
		int count; cin >> count;
		vector<int> singer(count);
		for (size_t i = 0; i < count; i++)
		{
			cin >> singer[i];
			if (i == 0) continue;
			if (singers[singer[i]].find(singer[i - 1]) != singers[singer[i]].end())continue;
			singers[singer[i]].insert(singer[i - 1]);
			indegree[singer[i - 1]] += 1;				
		}
	}
	stack<int> rslt;
	if (topologySort(singers, indegree, rslt, n))
	{
		while (!rslt.empty())
		{
			cout << rslt.top() <<"\n";
			rslt.pop();
		}
	}
	else
	{
		cout << 0;
	}
	return 0;
}