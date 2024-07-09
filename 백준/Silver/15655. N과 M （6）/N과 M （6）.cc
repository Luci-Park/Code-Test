#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int numbers[8];
int choices[8];
bool chosen[8] = { false };
void print()
{
	for (int i = 0; i < M; i++)
		cout << choices[i] << " ";
	cout << "\n";
}
void func(int depth, int start)
{
	if (depth == M) { print(); return; }
	for (int i = start; i < N; i++)
	{
		if (chosen[i]) continue;
		choices[depth] = numbers[i];
		chosen[i] = true;
		func(depth + 1, i + 1);
		chosen[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> numbers[i];
	sort(numbers, numbers + N);
	func(0, 0);
    return 0;
}