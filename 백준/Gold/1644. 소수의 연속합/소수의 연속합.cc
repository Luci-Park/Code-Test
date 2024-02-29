#include <iostream>
#include <list>
using namespace std;
bool numbers[4000001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	list<int> primes;
	int n, answer = 0;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		if (numbers[i]) continue;
		primes.push_back(i);
		int k = 2;
		while (k * i <= n) numbers[k++ * i] = true;
	}
	int sum = 0;
	auto add = primes.begin();
	auto sub = primes.begin();
	while (add != primes.end())
	{
		if (sum < n)
		{
			sum += *add;
			++add;
		}
		else if (sum == n)
		{
			answer += 1;
			sum -= *sub;
			++sub;
		}
		else if (sum > n)
		{
			sum -= *sub;
			++sub;
		}
	}
	while (sum > n && sub != primes.end())
	{
		sum -= *sub;
		++sub;
	}
	if (sum == n) answer += 1;

	cout << answer;


	return 0;
}