#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int gear[4][8];
	int idx[4] = { 0, 0, 0, 0 }; // 12시 방향
	int k;
	for (int i = 0; i < 4; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < 8; j++)
			gear[i][j] = str[j] - '0';
	}
	cin >> k;
	while (k--)
	{
		int num, dir;
		cin >> num >> dir;
		stack<pair<int, int>> s;
		bool visited[4] = { false, false, false, false };
		s.push({ num - 1, dir * -1 });
		visited[num - 1] = true;
		while (!s.empty())
		{
			int gearNum = s.top().first;
			int gearDir = s.top().second;
			s.pop();
			if (gearNum + 1 < 4 && !visited[gearNum + 1]) // right
			{
				int rightIdx = (idx[gearNum] + 2) % 8;
				int leftIdx = (idx[gearNum + 1] - 2 + 8) % 8;
				if (gear[gearNum][rightIdx] != gear[gearNum + 1][leftIdx])
				{
					s.push({ gearNum + 1, gearDir * -1 });
					visited[gearNum + 1] = true;
				}
			}
			if(gearNum - 1 >= 0 && !visited[gearNum - 1]) // left
			{
				int rightIdx = (idx[gearNum - 1] + 2) % 8;
				int leftIdx = (idx[gearNum] - 2 + 8) % 8;
				if (gear[gearNum - 1][rightIdx] != gear[gearNum][leftIdx])
				{
					s.push({ gearNum - 1, gearDir * -1 });
					visited[gearNum - 1] = true;
				}
			}
			idx[gearNum] = (idx[gearNum] + gearDir + 8) % 8;
		}
	}

	cout << gear[0][idx[0]] * 1 + gear[1][idx[1]] * 2 + gear[2][idx[2]] * 4 + gear[3][idx[3]] * 8;
	return 0;
}