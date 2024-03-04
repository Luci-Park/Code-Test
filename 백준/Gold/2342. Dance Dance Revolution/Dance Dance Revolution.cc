#include <iostream>
#include <vector>
using namespace std;
vector<int> pos;
int dp[100001][5][5];
int cost(int startPos, int targetPos)
{
	if (startPos == 0) return 2;
	if (startPos == targetPos) return 1;
	if (abs(startPos - targetPos) == 2) return 4;
	return 3;
}
int cost(size_t depth, int right, int left)
{
	if (depth >= pos.size()) return 0;
	int p = pos[depth];
	if (dp[depth][right][left]) return dp[depth][right][left];
	if (p == right)	dp[depth][right][left] = cost(right, p) + cost(depth + 1, p, left);
	else if (p == left) dp[depth][right][left] = cost(left, p) + cost(depth + 1, right, p);
	else {
		int rightCost = cost(right, p) + cost(depth + 1, p, left);
		int leftCost = cost(left, p) + cost(depth + 1, right, p);
		dp[depth][right][left] = min(rightCost, leftCost);
	}
	
	return dp[depth][right][left];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (true)
	{
		int a; cin >> a;
		if (a == 0) break;
		pos.push_back(a);
	}

	cout << cost(0, 0, 0);

	return 0;
}