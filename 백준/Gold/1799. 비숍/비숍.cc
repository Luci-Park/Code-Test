#include <iostream>
using namespace std;
using pii = pair<int, int>;
int n;
bool place[10][10];
int maxCount = 0;
pii bishops[100];
bool isDiagonal(pii a, pii b)
{
	return abs(a.first - b.first) == abs(a.second - b.second);
}
void dfs(int depth, int ny, int nx, int offset)
{
	if (depth > maxCount) maxCount = depth;
	for (int i = ny; i < n; i++)
	{
		int j = i == ny ? nx : (i + offset) % 2;
		
		for (; j < n; j+= 2)
		{
			if (!place[i][j]) continue;
			bool noDag = true;
			for (int k = 0; k < depth; k++)
			{
				if (!isDiagonal(bishops[k], { i, j })) continue;
				noDag = false;
				break;
			}
			if (!noDag) continue;
			bishops[depth] = { i, j };
			dfs(depth + 1, i, j + 2, offset);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> place[i][j];
	dfs(0, 0, 0, 0);
	int answer = maxCount;
	maxCount = 0;
	dfs(0, 0, 1, 1);
	cout << answer + maxCount;

	return 0;
}