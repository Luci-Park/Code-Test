#include <iostream>
using namespace std;
int main()
{
	int n;
	float scores[1000];
	float average = 0;
	float m = 0;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> scores[i];
		if (scores[i] > m) m = scores[i];
		average += scores[i];
	}
	average = average / (m * n) * 100;
	cout << average;
	return 0;
}