#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int N, M, K;
int stickers[100][10][10];
int stickSize[100][2];
int map[50][50] = { 0 };

void rotate(int idx)
{
	int sticker[10][10];
	memset(sticker, 0, sizeof(sticker));
	int r = stickSize[idx][0], c = stickSize[idx][1];
	for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
			sticker[i][j] = stickers[idx][r - j - 1][i];
	memmove(stickers[idx], sticker, sizeof(sticker));
	stickSize[idx][0] = c;
	stickSize[idx][1] = r;
}

bool check(int idx, int y, int x)
{
	int r = stickSize[idx][0], c = stickSize[idx][1];
	queue<pair<int, int>> rollback;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (stickers[idx][i][j])
			{
				if (map[y + i][x + j] == 0)
				{
					map[y + i][x + j] = 1;
					rollback.push({ y + i, x + j });
				}
				else
				{
					while (!rollback.empty())
					{
						map[rollback.front().first][rollback.front().second] = 0;
						rollback.pop();
					}
					return false;
				}
			}
		}
	}
	return true;
}
int count()
{
	int add = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			add += map[i][j];
	return add;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int k = 0; k < K; k++)
	{
		cin >> stickSize[k][0] >> stickSize[k][1];
		memset(stickers[k], 0, sizeof(stickers[k]));
		for (int i = 0; i < stickSize[k][0]; i++)
			for (int j = 0; j < stickSize[k][1]; j++)
				cin >> stickers[k][i][j];
	}
	for (int k = 0; k < K; k++)
	{
		for (int a = 0; a < 4; a++)
		{
			bool result = 0;
			for (int ny = 0; ny <= N - stickSize[k][0]; ny++)
			{
				for (int nx = 0; nx <= M - stickSize[k][1]; nx++)
				{
					result = check(k, ny, nx);
					if (result) break;
				}
				if (result) break;
			}
			if (result) break;
			if(a < 3) rotate(k);
		}
	}
	cout << count();
	return 0;
}