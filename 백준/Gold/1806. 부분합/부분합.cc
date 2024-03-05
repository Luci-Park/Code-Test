#include <iostream>
using namespace std;

int numbers[100000];
int sol(int n, long s)
{
	long sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		cin >> numbers[i];
		if (numbers[i] >= s) return 1;
		sum += numbers[i];
	}
	if (sum < s) return 0;
	int answer = n;
	sum = 0;
	int left = 0, right = 0;
	while (left < n)
	{
		if (sum < s)
		{
			if (right < n) sum += numbers[right++];
			else break;
		}
		else
		{
			int length = right - left;
			if (length < answer) answer = length;
			sum -= numbers[left++];
		}
	}
	return answer;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long s;
	cin >> n >> s;
	cout << sol(n, s);
	return 0;
}