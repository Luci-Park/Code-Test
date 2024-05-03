#include <iostream>
using namespace std;

long N, B, C;
long As[1000000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (long i = 0; i < N; i++)
		cin >> As[i];
	cin >> B >> C;
	long long count = N;
	for (long i = 0; i < N; i++)
	{
		As[i] -= B;
		if (As[i] <= 0) continue;
		count += (As[i] + C - 1) / C;
	}
	cout << count;
	return 0;
}