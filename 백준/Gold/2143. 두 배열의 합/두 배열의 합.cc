#include <iostream>
#include <map>
using namespace std;
void GetInput(int arr[1000], int n)
{
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}
void GetSubSum(int arr[1000], int n, map<long, long>& m)
{
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += arr[j];
			auto iter = m.find(sum);
			if (iter == m.end()) m.insert({ sum, 1 });
			else iter->second += 1;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	map<long, long> sumA, sumB;
	int t, n, m;
	int A[1000], B[1000];
	cin >> t;
	cin >> n;
	GetInput(A, n);
	cin >> m;
	GetInput(B, m);
	GetSubSum(A, n, sumA);
	GetSubSum(B, m, sumB);
	long answer = 0;
	for (auto iterA = sumA.begin(); iterA != sumA.end(); ++iterA)
	{
		auto iterB = sumB.find(t - iterA->first);
		if (iterB == sumB.end())continue;
		answer += iterA->second * iterB->second;
	}
	cout << answer;
	return 0;
}