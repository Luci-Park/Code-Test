#include <iostream>

int main()
{
	int a, b, c;
	while (1)
	{
		std::cin >> a >> b >> c;
		if (!a || !b || !c) break;
		int aa = a * a;
		int bb = b * b;
		int cc = c * c;
		if (aa == bb + cc || bb == aa + cc || cc == aa + bb)
			std::cout << "right\n";
		else
			std::cout << "wrong\n";
	}
	return 0;
}