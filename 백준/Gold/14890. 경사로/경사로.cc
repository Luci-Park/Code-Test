#include <iostream>
using namespace std;

int arr[100][100];

int calculate(bool horizontal, int N, int L)
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		int p = 0;
		int level = horizontal ? arr[i][0] : arr[0][i];
		bool flag = true;
		bool checking = false;
		for (int j = 1; j < N; j++)
		{
			int target = horizontal ? arr[i][j] : arr[j][i];
			if (target != level)
			{
				if (checking) { flag = false; break; }
				if (level - target == -1) // 앞에 더 큰게 있음
				{
					if (j - p < L)
					{
						flag = false;
						break;
					}
				}
				else if (level - target == 1) // 더 작아지기 시작했다.
				{
					checking = true;
				}
				else
				{
					flag = false;
					break;
				}
				p = j;
				level = target;
			}
			if (checking && j - p + 1 >= L) { checking = false; p += L; }
		}
		if (flag && checking) flag = false;
		count += flag;
	}
	return count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	int L;

	cin >> N >> L;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	int count = calculate(true, N, L) + calculate(false, N, L);

	cout << count;
	return 0;
}