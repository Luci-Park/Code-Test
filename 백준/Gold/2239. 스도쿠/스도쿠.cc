#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pir;

int sudoku[9][9];
int answer[9][9];
vector<pir> spaces;
bool isValid(int y, int x)
{
	for (int i = 0; i < 9; i++)
	{
		if (i != y && sudoku[i][x] == sudoku[y][x])
			return false;
		if (i != x && sudoku[y][i] == sudoku[y][x])
		{
			int t = sudoku[y][i];
			return false;
		}
	}
	int row = y / 3 * 3;
	int col = x / 3 * 3;
	for (int i = row; i < row + 3; i++)
		for (int j = col; j < col + 3; j++)
			if (i != y && j != x && sudoku[i][j] == sudoku[y][x])
				return false;
	return true;
}
bool SetSudoku(int depth)
{
	if (depth == spaces.size())
		return true;
	int y = spaces[depth].first;
	int x = spaces[depth].second;
	for (int i = 1; i <= 9; i++)
	{
		sudoku[y][x] = i;
		if (isValid(y, x) && SetSudoku(depth + 1))
			return true;
	}
	sudoku[y][x] = 0;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int temp[9][9] = {
		{1, 4, 3, 6, 2, 8, 5, 7, 9},
		{5, 7, 2, 1, 3, 9, 4, 6, 8},
		{9, 8, 6, 7, 5, 4, 2, 3, 1},
		{3, 9, 1, 5, 4, 2, 7, 8, 6},
		{4, 6, 8, 9, 1, 7, 3, 5, 2},
		{7, 2, 5, 8, 6, 3, 9, 1, 4},
		{2, 3, 7, 4, 8, 1, 6, 9, 5},
		{6, 1, 9, 2, 7, 5, 8, 4, 3},
		{8, 5, 4, 3, 9, 6, 1, 2, 7}
	};

	for (int i = 0; i < 9; i++)
	{
		string s; cin >> s;
		for (int j = 0; j < 9; j++)
		{
			sudoku[i][j] = s[j] - '0';
			if (sudoku[i][j] == 0)
				spaces.push_back({ i, j });
			answer[i][j] = temp[i][j];
		}
	}
	SetSudoku(0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << sudoku[i][j];
		cout << "\n";
	}

	return 0;
}