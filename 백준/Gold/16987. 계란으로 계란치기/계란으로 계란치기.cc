#include <iostream>
using namespace std;

int eggs[8][2];
int N;
int func(int depth, int count)
{
	if (depth == N) return count;
	if (eggs[depth][0] <= 0) return func(depth + 1, count);

	int maxN = count;
	for (int i = 0; i < N; i++)
	{
		if (i == depth) continue;
		if (eggs[i][0] <= 0) continue;
		eggs[depth][0] -= eggs[i][1];
		eggs[i][0] -= eggs[depth][1];
		int tempCount = 0;
		if (eggs[depth][0] <= 0) tempCount += 1;
		if (eggs[i][0] <= 0) tempCount += 1;
		int n = func(depth + 1, count + tempCount);
		maxN = max(n, maxN);
		eggs[depth][0] += eggs[i][1];
		eggs[i][0] += eggs[depth][1];
	}
	return maxN;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> eggs[i][0] >> eggs[i][1];

	cout << func(0, 0);
	return 0;
}