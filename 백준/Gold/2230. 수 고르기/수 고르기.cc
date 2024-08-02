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
	for (int i = 0; i < n; i++)
	{
		if (arr[i] + m > arr[n - 1]) break;
		auto it = lower_bound(arr, arr + n, arr[i] + m);
		int diff = (*it) - arr[i];
		if (diff >= m && (answer == -1 || diff < answer))
			answer = diff;
	}
	cout << answer;

	return 0;
}