#include <iostream>
#include <list>
using namespace std;
int n;
int S[20][20];
list<int> start, link;
int st = 0, lk = 0;

int dfs(int depth = 0)
{
	if (depth == n)
		return abs(st - lk);
	int minNum = 1000000;
	if (start.size() < n / 2)
	{
		for (int it : start)
			st += S[depth][it] + S[it][depth];
		start.push_back(depth);
		minNum = min(minNum, dfs(depth + 1));
		start.pop_back();
		for (int it : start)
			st -= S[depth][it] + S[it][depth];
	}
	if (link.size() < n / 2)
	{
		for (int it : link)
			lk += S[depth][it] + S[it][depth];
		link.push_back(depth);
		minNum = min(minNum, dfs(depth + 1));
		link.pop_back();
		for (int it : link)
			lk -= S[depth][it] + S[it][depth];
	}
	return minNum;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> S[i][j];
	cout << dfs();
	
	return 0;
}