#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = unsigned long long;
ll arr[1000];
vector<ll> two;
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			two.emplace_back(arr[i] + arr[j]);
	sort(two.begin(), two.end());
	two.erase(unique(two.begin(), two.end()), two.end());

	ll answer = 0;
	for(int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] <= answer) continue;
			if (binary_search(two.begin(), two.end(), arr[j] - arr[i]))
				answer = arr[j];
		}

	cout << answer;
	return 0;
}