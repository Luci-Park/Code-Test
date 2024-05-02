#include <iostream>
using namespace std;
struct Shark
{
	int r;
	int c;
	int s;
	int d;
	int z;
	bool e;
};
int dy[] = { 0, -1, 1, 0, 0 };
int dx[] = { 0, 0, 0, 1, -1 };
int map[101][101] = { 0, };
Shark sharks[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int R, C, M;
	cin >> R >> C >> M;
	int size = 0;
	int pos = 1;
	for (int i = 1; i <= M; i++)
	{
		cin >> sharks[i].r >> sharks[i].c
			>> sharks[i].s >> sharks[i].d
			>> sharks[i].z;
		sharks[i].e = true;
		map[sharks[i].r][sharks[i].c] = i;
	}
	while (pos <= C)
	{
		for (int i = 1; i <= R; i++)
		{
			if (map[i][pos])
			{
				int idx = map[i][pos];
				size += sharks[idx].z;
				sharks[idx].e = false;
				map[i][pos] = 0;
				break;
			}
		}
		for (int i = 1; i <= M; i++)
		{
			if (!sharks[i].e) continue;
			if(map[sharks[i].r][sharks[i].c] == i) 
				map[sharks[i].r][sharks[i].c] = 0;
			if (sharks[i].d <= 2)
			{
				int d = (sharks[i].s * dy[sharks[i].d]) %((R - 1) * 4);
				int r = sharks[i].r;
				bool dirChanged = false;
				while (d != 0)
				{
					if (r + d > R) 
					{  
						d -= R - r;
						d *= -1;
						r = R;
						dirChanged = !dirChanged; 
					}
					else if (r + d < 1)
					{
						d += r - 1;
						d *= -1;
						r = 1;
						dirChanged = !dirChanged;
					}
					else
					{
						r += d;
						d = 0;
					}
				}
				if (dirChanged && sharks[i].d == 1) sharks[i].d = 2;
				else if (dirChanged && sharks[i].d == 2) sharks[i].d = 1;
				sharks[i].r = r;
			}
			else
			{
				int d = (sharks[i].s * dx[sharks[i].d]) % ((C - 1) * 4);
				int c = sharks[i].c;
				bool dirChanged = false;
				while (d != 0)
				{
					if (c + d > C)
					{
						d -= C - c;
						d *= -1;
						c = C;
						dirChanged = !dirChanged;
					}
					else if (c + d < 1)
					{
						d += c - 1;
						d *= -1;
						c = 1;
						dirChanged = !dirChanged;
					}
					else
					{
						c += d;
						d = 0;
					}
				}
				if (dirChanged && sharks[i].d == 3) sharks[i].d = 4;
				else if (dirChanged && sharks[i].d == 4) sharks[i].d = 3;
				sharks[i].c = c;
			}
			if (map[sharks[i].r][sharks[i].c] < i)
			{
				int idx = map[sharks[i].r][sharks[i].c];
				if (sharks[idx].z < sharks[i].z) 
					sharks[idx].e = false;
				else 
					sharks[i].e = false;
			}
			if(sharks[i].e)
				map[sharks[i].r][sharks[i].c] = i;
		}
		pos++;
	}
	cout << size;

	return 0;
}