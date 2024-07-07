#include <iostream>
using namespace std;

char strs[6561][6562];
int N;

void setup(int size, int y, int x)
{
	if (size == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == 1 && j == 1) strs[y+i][x + j] = ' ';
				else strs[y + i][x + j] = '*';
			}
			strs[y + i][x + 3] = '\0';
		}
	}
	else
	{
		int nsize = size / 3;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == 1 && j == 1)
				{
					for (int a = nsize; a < nsize * 2; a++)
						for (int b = nsize; b < nsize * 2; b++)
							strs[y + a][x + b] = ' ';
				}
				else
				{
					int ny = y + i * nsize, nx = x + j * nsize;
					setup(nsize, ny, nx);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	setup(N, 0, 0);
	for (int i = 0; i < N; i++)
		cout << strs[i] << "\n";
    return 0;
}