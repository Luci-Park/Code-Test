#include <iostream>
using namespace std;
int numbers[1000001] = { 0, };
int prevNum[1000001] = { 0, };
int n;
bool update(int idx, int target)
{
	if (target > n) return false;
	if (!numbers[target] || numbers[target] > numbers[idx] + 1)
	{
		numbers[target] = numbers[idx] + 1;
		prevNum[target] = idx;
	}
	return target == n;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		update(i, i * 3);
		update(i, i * 2);
		update(i, i + 1);
	}
	int idx = n;
	cout << numbers[n]<<"\n";
	while (idx > 0)
	{
		cout << idx << " ";
		idx = prevNum[idx];
	}

	return 0;
}