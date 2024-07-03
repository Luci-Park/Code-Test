#include <iostream>
#include <queue>

using namespace std;
int visited[1000001] = { 0 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int f, s, g;
	int move[2];
	cin >> f >> s >> g >> move[0] >> move[1];
	move[1] *= -1;
	queue<int> q;
	q.push(s);
	
	visited[s] = 1;

	while (!q.empty())
	{
		s = q.front(); q.pop();
		if (s == g) break;
		int v = visited[s];
		for (int i = 0; i < 2; i++)
		{
			int ns = s + move[i];
			if (ns <= 0 || ns > f || visited[ns]) continue;
			visited[ns] = v + 1;
			q.push(ns);
		}
	}
	if (visited[g]) cout << (visited[g] - 1);
	else cout << "use the stairs";

    return 0;
}