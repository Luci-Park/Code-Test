#include <iostream>
using namespace std;

int N;
int T[15];
int P[15];

int dfs(int depth)
{
	if (depth >= N) return 0;
	int a = (depth + T[depth] <= N) ? dfs(depth + T[depth]) + P[depth] : 0;
	int b = dfs(depth + 1);
	return max(a, b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> T[i] >> P[i];

	cout << dfs(0);

	return 0;
}