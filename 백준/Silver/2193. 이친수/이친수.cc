#include <iostream>
using namespace std;
int n;
long nums[91][2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	nums[1][0] = 0;
	nums[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		nums[i][0] = nums[i - 1][0] + nums[i - 1][1];
		nums[i][1] = nums[i - 1][0];
	}
	cout << nums[n][0] + nums[n][1];
	return 0;
}