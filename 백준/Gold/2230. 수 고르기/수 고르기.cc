#include <iostream>
#include <algorithm>
using namespace std;
int arr[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int answer = -1;
	sort(arr, arr + n);
	int lo = 0, hi = 0;
	while (answer != m && lo < n && hi < n)
	{
		while (arr[hi] - arr[lo] < m) hi++;
		int diff = arr[hi] - arr[lo];
		if (answer == -1 || diff < answer) answer = diff;
		lo++;
	}
	cout << answer;

	return 0;
}