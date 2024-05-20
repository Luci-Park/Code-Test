#include <iostream>
using namespace std;
using ll = long long;
using pll = pair<long, long>;

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
	return (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
}
int process(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
	ll rslt = ccw(x1, y1, x2, y2, x3, y3);
	if (rslt < 0) return -1;
	else if (rslt == 0) return 0;
	else return 1;
}
bool intersect(pll a, pll b, pll c, pll d)
{
	int abc = process(a.first, a.second, b.first, b.second, c.first, c.second);
	int abd = process(a.first, a.second, b.first, b.second, d.first, d.second);
	int cda = process(c.first, c.second, d.first, d.second, a.first, a.second);
	int cdb = process(c.first, c.second, d.first, d.second, b.first, b.second);

	if (abc * abd == 0 && cda * cdb == 0)
	{
		if (b < a) swap(a, b);
		if (d < c) swap(c, d);
		return c <= b && a <= d;
	}
	return (abc * abd <= 0 && cda * cdb <= 0);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll x1, x2, x3, x4, y1, y2, y3, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	cout << intersect({ x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 });
	return 0;
}