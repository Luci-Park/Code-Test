#include <iostream>
#include <map>
using namespace std;
using ll = long long;
ll N, S, answer = 0;
ll arr[41];
map<ll, ll> m;

void left(ll s, ll sum)
{
	if (s == N / 2)
		m[sum]++;
	else
	{
		left(s + 1, sum);
		left(s + 1, sum + arr[s]);
	}
}

void right(ll s, ll sum)
{
	if (s == N)
		answer += m[S - sum];
	else
	{
		right(s + 1, sum);
		right(s + 1, sum + arr[s]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	left(0, 0);
	right(N / 2, 0);
	if (S == 0) answer -= 1;
	cout << answer;

	return 0;
}