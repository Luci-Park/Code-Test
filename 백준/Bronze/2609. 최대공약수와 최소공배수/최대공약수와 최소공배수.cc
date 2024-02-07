#include <iostream>
using namespace std;
int GCD(int a, int b)
{
	while (b)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main()
{
	int a, b;
	cin >> a >> b;
	int gcd = GCD(a, b);
	int lcm = a * b / gcd;
	cout << gcd << "\n" << lcm;
	return 0;
}