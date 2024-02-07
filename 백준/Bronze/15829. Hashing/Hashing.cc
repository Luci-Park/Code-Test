#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long M = 1234567891;
	long long r = 1;
	long long answer = 0;
	int numberOfNum;
	string numbers;
	cin >> numberOfNum >> numbers;
	for (int i = 0; i < numberOfNum; i++)
	{
		answer = (answer + (numbers[i] - 'a' + 1) * r) % M;
		r = (r * 31) % M;
	}
	cout << answer;

	return 0;
}
