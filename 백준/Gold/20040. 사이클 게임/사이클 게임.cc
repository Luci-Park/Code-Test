#include <iostream>
using namespace std;
int parent[500000];
int height[500000];

int find(int a)
{
	if (parent[a] != a)
		parent[a] = find(parent[a]);
	return parent[a];
}

bool join(int a, int b)
{
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) return false;
	if (height[pa] < height[pb])
		swap(pa, pb);
	parent[pb] = pa;
	if (height[pa] == height[pb])
		height[pa]++;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; 
	int answer = 0;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
		height[i] = 0;
	}

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (!join(a, b) && answer == 0)
			answer = i;
	}
	cout << answer;
	return 0;
}