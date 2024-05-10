#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (true)
	{
		vector<int> nums(3);
		for (int i = 0; i < 3; i++)
			cin >> nums[i];
		if (nums[0] == 0) break;
		sort(nums.begin(), nums.end());
		if (nums[2] >= nums[1] + nums[0])
			cout << "Invalid\n";
		else if (nums[0] == nums[1] && nums[1] == nums[2])
			cout << "Equilateral\n";
		else if (nums[0] == nums[1] || nums[1] == nums[2])
			cout << "Isosceles\n";
		else
			cout << "Scalene\n";
	}

	return 0;
}