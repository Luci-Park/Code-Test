#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long a, b, v;
	cin >> a >> b >> v;
	v -= a;
	a -= b;
	long answer = v / a + 1;
	if (v % a != 0) ++answer;
	cout << answer;
	return 0;
}