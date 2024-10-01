#include <iostream>
#include <vector>
#include <algorithm>

int height[9];
bool used[9] = { false };

bool checkHeight(int depth, int sum, int found)
{
	if (depth == 9)
		return sum == 100 && found == 7;

	used[depth] = true;
	bool flag = checkHeight(depth + 1, sum + height[depth], found + 1);
	if (flag) return true;
	used[depth] = false;
	flag = checkHeight(depth + 1, sum, found);
	return flag;
}

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < 9; i++)
		cin >> height[i];

	sort(height, height + 9);
	checkHeight(0, 0, 0);
	for (int i = 0; i < 9; i++)
		if (used[i])
			cout << height[i] << "\n";

	return 0;
}