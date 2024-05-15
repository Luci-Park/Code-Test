#include <iostream>
using namespace std;
using uint = unsigned int;

uint parent[100001];
uint g, p;

uint get_parent(uint a)
{
	if (parent[a] != a) parent[a] = get_parent(parent[a]);
	return parent[a];
}

void join(uint a, uint b)
{
	uint pa = get_parent(a);
	uint pb = get_parent(b);
	if (pb < pa) swap(pb, pa);
	parent[pb] = pa;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> g >> p;
	for (int i = 0; i <= g; i++)
		parent[i] = i;

	bool finished = false;
	uint answer = 0;
	for (int i = 1; i <= p; i++)
	{
		uint n; cin >> n;
		if (finished) continue;
		uint par = get_parent(n);
		if (!par)
		{
			finished = true;
			answer = i - 1;
		}
		else
		{
			join(par - 1, par);
		}
	}
	if (!finished) answer = p;
	cout << answer;
	return 0;
}